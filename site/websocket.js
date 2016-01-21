#!/usr/bin/env node
/*
*
* NodeJS script om websocket data te simuleren 
*
*/

var WebSocketServer = require('websocket').server;
var http = require('http');
////////////////
var running = false;
var time = 0;
var currentStep = 0;
var selectedWashingProgram = 0;


var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8080, function() {
    console.log((new Date()) + ' Server is listening on port 8080');
});

wsServer = new WebSocketServer({
    httpServer: server,
    // You should not use autoAcceptConnections for production
    // applications, as it defeats all standard cross-origin protection
    // facilities built into the protocol and the browser.  You should
    // *always* verify the connection's origin and decide whether or not
    // to accept it.
    autoAcceptConnections: false
});

var status = 0;
var washingPrograms = 
    [
        {
            "desc":"Washing program 1",
            "stepSize":4,
            "steps":[
                 {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 30
                },
                {
                   "degrees": 60,
                    "rpm": 1200,
                    "water": 90,
                    "time": 40
                },
                {
                    "degrees": 60,
                    "rpm": 1300,
                    "water": 90,
                    "time": 30
                },
                {
                    "degrees": 60,
                    "rpm": 1400,
                    "water": 100,
                    "time": 50
                },
                {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 25
                }

            ]
        }
        ,
        {
            "desc":"Washing program 2",
            "stepSize":5,
            "steps":[
                 {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 1000
                },
                {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 1000
                },
                {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 1000
                },
                {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 1000
                },
                {
                    "degrees": 60,
                    "rpm": 1600,
                    "water": 90,
                    "time": 1000
                }

            ]
        }
    ];
wsServer.on('request', function(request) {

    var connection = request.accept('echo-protocol', request.origin);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log('Received Message: ' + message.utf8Data);
            var data = JSON.parse(message.utf8Data);
            
            if(data.event == "getWashingPrograms")
            {
                var msg = {
                    "event":"washingProgramList"
                };
                msg['washingPrograms'] = washingPrograms
                
                connection.sendUTF(JSON.stringify(msg));
            }
            else if(data.event == "statusUpdate")
            {
                sendUpdate();
            }
            else if(data.event == "stopWashingProgram")
            {
                running = false;
                time = 0;
                status = 0;
                sendUpdate();
                //clearInterval(interval);
            }
            else if(data.event == "startWashingProgram")
            {
                console.log("Starting was");
                selectedWashingProgram = data.id;
                if(running == false){
                    running = true;
                    time = 0;
                    currentStep = 0;
                    status = 1;
                }       
            }
        }
        else if (message.type === 'binary') {
            console.log('Received Binary Message of ' + message.binaryData.length + ' bytes');
            connection.sendBytes(message.binaryData);
        }
    });
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
    });
    
});

var interval = setInterval(function() {
        if(running){
          time++;
          if(time > washingPrograms[selectedWashingProgram].steps[currentStep]["time"])
          {
              time = 0;
              currentStep++;
              if(currentStep == washingPrograms[selectedWashingProgram].steps.length){
                  currentStep = 0;
              }
          }
          sendUpdate();
        }
    }, 1000);

function sendUpdate()
{
    if(running)
    {
        var msg = {
            "event":"statusUpdate",
            "washingProgram":{
                "currentStep":currentStep,
                "totalSteps":washingPrograms[selectedWashingProgram].steps.length,
                "ActiveWashingProgram": selectedWashingProgram,
                "data":{
                    "status":status, // 0 = off, 1 = on, -1 = error
                    "currentDegrees":washingPrograms[selectedWashingProgram].steps[currentStep]["degrees"],
                    "currentRpm":washingPrograms[selectedWashingProgram].steps[currentStep]["rpm"],
                    "currentWaterLevel":washingPrograms[selectedWashingProgram].steps[currentStep]["water"],
                    "timeRunning":time,
                    "totalTime":washingPrograms[selectedWashingProgram].steps[currentStep]["time"]
                }
            }
        };
    }
    else{
        var msg = {
            "event":"statusUpdate",
            "washingProgram":{
                "currentStep":currentStep,
                "totalSteps":washingPrograms[selectedWashingProgram].steps.length,
                "ActiveWashingProgram": selectedWashingProgram,
                "data":{
                    "status":status, // 0 = off, 1 = on, -1 = error
                    "currentDegrees":0,
                    "currentRpm":0,
                    "currentWaterLevel":0,
                    "timeRunning":0,
                    "totalTime":washingPrograms[selectedWashingProgram].steps[currentStep]["time"]
                }
            }
        };
    }
    wsServer.broadcast(JSON.stringify(msg));
}
