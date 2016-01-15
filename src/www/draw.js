$( document ).ready(function() {
    
    var c = document.getElementById("statusCanvas");
    var context = c.getContext('2d');
    var times = [];
    var currentStepTime = 0;
    var steps = times.length + 1;
    var selectedStep = 0;
    
    var textColor = 'black';
    var doneColor = 'green';
    var busyColor = 'yellow';
    var waitingColor = 'grey';
    
    var status;
    
    var loadedWasPrograms;
    
    var stepCount;
    var washingProgram = { 
        "steps":[{ "settings": [
                    {"degrees": 0},
                    {"rpm": 0},
                    {"water": 0},
                    {"time": 0}
                ]},{ "settings": [
                    {"degrees": 0},
                    {"rpm": 0},
                    {"water": 0},
                    {"time": 0}
                ]}]   
        };
    var step = {"settings": [
                    {"degrees": 0},
                    {"rpm": 0},
                    {"water": 0},
                    {"time": 5}
        ]};
    
    window.addEventListener('resize', resizeCanvas, false);

    function resizeCanvas() {
            c.width = window.innerWidth - 20;
            draw(); 
    }
    resizeCanvas();
    hideShowItems();
    
    if ("WebSocket" in window) {
        ws = new WebSocket("ws://127.0.0.1:8081", 'echo-protocol');
        ws.onopen = function(evt) { onOpen(evt) };
        ws.onclose = function(evt) { onClose(evt) };
        ws.onmessage = function(evt) { onMessage(evt) };
        ws.onerror = function(evt) { onError(evt) };
    }
    
    function onOpen (evt) {
        console.log("connection opened");
        ws.send("{\"event\":\"statusUpdate\"}");
    }
    
    function onMessage (evt){
        console.log(evt.data);
        var data = JSON.parse(evt.data);
        
        if(data.event == "washingProgramList"){
            handleWashingList(data.washingPrograms);
            populateSelectors();
        } else if(data.event == "statusUpdate"){
            handleStatusUpdate(data.washingProgram);
        }
        hideShowItems();
    }
    
    function onClose (evt){
        console.log("connection closed");
    }
    
    function onError (evt){
        console.log("websocket error" + evt.data);
    }
    
    function sendMessage() {
        ws.send(text);
    }
    
    function closeConnection() {
        ws.close();
    }
    
    function draw() {
        var c = document.getElementById("statusCanvas");
        var context = c.getContext('2d');
        var centerY = c.height / 2;
        var radius = 10;
        var margin = 50;
        context.lineWidth = 5;

        context.font = "30px Arial";
        context.textAlign = "center";
        
        var dist = (c.width - margin * 2) / (steps - 1); 
        
        context.clearRect(0,0,c.width,c.height);
        
        context.fillText("Huidige stap: " + selectedStep + 1, margin + dist * i, centerY - radius * 2);
        
        for(var i = 0; i < steps; i++) {          
            context.fillStyle = textColor;
            
            if(i < steps - 1){
                context.fillText("stap " + (i + 1), margin + dist * i, centerY - radius * 2);
            } else {
                context.fillText("Klaar" , margin + dist * i, centerY - radius * 2);
            }
            
            if(i == selectedStep && status == 1){
                context.fillStyle = busyColor;
            } else if (i < selectedStep) {
                context.fillStyle = doneColor;
            } else {
                context.fillStyle = waitingColor;
            }
            
            if(i < steps - 1){
                if(i == selectedStep && status == 1){
                    context.strokeStyle = busyColor;
                    context.beginPath();
                    context.moveTo(margin + dist * i, c.height / 2);
                    context.lineTo(margin + dist * i + (dist / times[selectedStep] * currentStepTime) , c.height / 2);
                    context.stroke();
                    
                    context.strokeStyle = waitingColor;
                    context.beginPath();
                    context.moveTo((margin + dist * i) + (dist / times[selectedStep] * currentStepTime), c.height / 2);
                    context.lineTo(margin + dist * (i + 1), c.height / 2);
                    context.stroke();
                    
                } else {
                    context.strokeStyle = context.fillStyle;
                    context.beginPath();
                    context.moveTo(margin + dist * i, c.height / 2);
                    context.lineTo(margin + dist * (i + 1), c.height / 2);
                    context.stroke();
                }
            }
            context.beginPath();
            context.arc(margin + dist * i, centerY, radius, 0, 2 * Math.PI, false);
            context.fill();
            context.strokeStyle = '#003300';
            context.stroke(); 
        }
    }
    
    function handleWashingList(data)
    {
        var sel = document.getElementById('wasSelector');
        loadedWasPrograms = data;
        sel.innerHTML = "";
        for(var j = 0; j < data.length; j++) {
            sel.innerHTML += "<option id=\"j\">" + data[j].desc + "</option>";
        }
    }
    
    function handleStatusUpdate(data)
    {   
        status = data["data"]["status"];
        
        selectedStep = data["currentStep"];
        steps = data["totalSteps"] + 1;
        currentStepTime = data["data"]["timeRunning"];
        if(status == 1) {
            selectedStep = data["currentStep"];
            steps = data["totalSteps"] + 1;
            var ActiveWashingProgram = data["ActiveWashingProgram"];

            var currentDegrees = data["data"]["currentDegrees"];
            var rpm = data["data"]["currentRpm"];
            var water = data["data"]["currentWaterLevel"];
            currentStepTime = data["data"]["timeRunning"];
            var totalStepTime = data["data"]["totalTime"];

            times[selectedStep] = totalStepTime;

            var statusText = status == 0 ? "Uit" : status == -1 ? "Error" : "Aan";

            document.getElementById("status").innerHTML = statusText;
            document.getElementById("water").innerHTML = water;
            document.getElementById("rpm").innerHTML = rpm;
            document.getElementById("temp").innerHTML = currentDegrees;
            document.getElementById("time").innerHTML = currentStepTime + "/" + totalStepTime;
        } else if(status == 0){
            ws.send("{\"event\":\"getWashingPrograms\"}");
        }
        
        draw();
    }
    
    function hideShowItems()
    {
        console.log(status);
        if(status == 0) {
            $('#waterSelector').show();
            $('#rpmSelector').show();
            $('#degreeSelector').show();
            $('#timeSelector').show();
            $('#wasSelector').show();
            $('#start').show();
            $('#stop').hide();
        } else if(status == 1) {
            $('#waterSelector').hide();
            $('#rpmSelector').hide();
            $('#degreeSelector').hide();
            $('#timeSelector').hide(); 
            $('#start').hide();
            $('#wasSelector').hide();
            $('#stop').show();
        }
    }
    
    $('#wasSelector').on('change', populateSelectors);
                         
    function populateSelectors(){
        var data = loadedWasPrograms[$('#wasSelector')[0].selectedIndex];
        console.log(data);
        var currentDegrees = data.steps[0]["degrees"];
        var rpm = data.steps[0]["rpm"];
        var water = data.steps[0]["water"];
        var total = 0;
        for(var i = 0; i < data.steps.length; i++){
            times[i] = data.steps[i]["time"];
            total += times[i];
        }
        steps = data.steps.length + 1;
        

        $('#waterSelector option:first-child').text(water);
        $('#rpmSelector option:first-child').text(rpm);
        $('#degreeSelector option:first-child').text(currentDegrees);
        $('#timeSelector option:first-child').text(total);
        
        $("#water").innerHTML = water;
        $("#rpm").innerHTML = rpm;
        $("#temp").innerHTML = currentDegrees;
        $("#time").innerHTML = total + " Seconde";
        draw();
    }
    
    $( "#start" ).click(function() {
        var msg = {
            "event":"startWashingProgram",
            "id": $("#wasSelector").selectedIndex,
            "washingProgram":{
                    "steps":[
                    {
                        "settings":[
                                {"degrees": $( "#degreeSelector option:selected" ).text()},
                                {"rpm": $( "#rpmSelector option:selected" ).text()},
                                {"water": $( "#waterSelector option:selected" ).text()},
                                {"time": $( "#timeSelector option:selected" ).text()}
                            ]
                    }, {
                        "settings":[
                            {"degrees": $( "#degreeSelector option:selected" ).text()},
                            {"rpm": $( "#rpmSelector option:selected" ).text()},
                            {"water": $( "#waterSelector option:selected" ).text()},
                            {"time": $( "#timeSelector option:selected" ).text()}
                    ]}, {
                        "settings":[
                                {"degrees": $( "#degreeSelector option:selected" ).text()},
                                {"rpm": $( "#rpmSelector option:selected" ).text()},
                                {"water": $( "#waterSelector option:selected" ).text()},
                                {"time": $( "#timeSelector option:selected" ).text()}
                    ]}, {
                        "settings":[
                                {"degrees": $( "#degreeSelector option:selected" ).text()},
                                {"rpm": $( "#rpmSelector option:selected" ).text()},
                                {"water": $( "#waterSelector option:selected" ).text()},
                                {"time": $( "#timeSelector option:selected" ).text()}
                            ]
                    },
                    
                ]},
            };
        ws.send(JSON.stringify(msg));
        $('#start').hide();
        $('#wasSelector').hide();
        $('#stop').show();
    });
    
    $( "#stop" ).click(function() {
        ws.send("{\"event\":\"stopWashingProgram\"}");
        status = 0;
    });
});
