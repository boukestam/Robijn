$( document ).ready(function() {

	$("#status").hide();
	$("#ipInput").val(window.location.href.replace(/.*?:\/\//g, "").replace("/", ""));
    
    var c = document.getElementById("statusCanvas");
    var context = c.getContext('2d');
    
	var currentStep = 0;
	var timeRunning = 0;
    
    var textColor = 'black';
    var doneColor = 'green';
    var busyColor = 'yellow';
    var waitingColor = 'grey';
    
    var status;
    
    var loadedWasPrograms;

	var connectHash = "";
    
    var stepCount;
    var hasLoadedPrograms = false;
	
	var currentWashingProgram = {};
	
	function getTotalTime(){
		var time = 0;
		
		if(currentWashingProgram.steps){
			for(var i = 0; i < currentWashingProgram.steps.length; i++){
				time += parseInt(currentWashingProgram.steps[i].time);
			}
		}
		
		return time;
	}
	
	function getNumSteps(){
		if(currentWashingProgram.steps){
			return currentWashingProgram.steps.length;
		}
		return 0;
	}
	
	function getCurrentStepTime(){
		var time = timeRunning;
		
		if(currentWashingProgram.steps){
			for(var i = 0; i < currentStep && i < currentWashingProgram.steps.length; i++){
				time -= parseInt(currentWashingProgram.steps[i].time);
			}
		}
		
		return time;
	}
	
	function getStepTime(index){
		if(currentWashingProgram.steps){
			if(index < currentWashingProgram.steps.length){
				return parseInt(currentWashingProgram.steps[index].time);
			}
		}
		return 0;
	}

	function draw() {
        var c = document.getElementById("statusCanvas");
		
		c.width = $(c).width();
		c.height = $(c).height();
		
        var context = c.getContext('2d');
		
        var centerY = c.height / 2;
		
        var radius = 10;
        var margin = 50;
		
        context.lineWidth = 5;
        context.font = "30px Arial";
        context.textAlign = "center";
		
		var numSteps = getNumSteps();
		var currentStepTime = getCurrentStepTime();
        
        var dist = (c.width - (margin * 2)) / numSteps; 
        
        context.clearRect(0,0,c.width,c.height);
        
        context.fillText("Huidige stap: " + currentStep + 1, margin + dist * i, centerY - radius * 2);
        
        for(var i = 0; i <= numSteps; i++) {          
            context.fillStyle = textColor;
			
            if(i < numSteps){
                context.fillText("Stap " + (i + 1), margin + dist * i, centerY - radius * 2);
            } else {
                context.fillText("Klaar" , margin + dist * i, centerY - radius * 2);
            }
            
            if(i == currentStep && status == 4){
                context.fillStyle = busyColor;
            } else if (i < currentStep) {
                context.fillStyle = doneColor;
            } else {
                context.fillStyle = waitingColor;
            }
            
            if(i < numSteps){
                if(i == currentStep && status == 4){
                    context.strokeStyle = busyColor;
					
                    context.beginPath();
                    context.moveTo(margin + dist * i, c.height / 2);
                    context.lineTo(margin + dist * i + (dist / getStepTime(currentStep) * currentStepTime) , c.height / 2);
                    context.stroke();
                    
                    context.strokeStyle = waitingColor;
                    
					context.beginPath();
                    context.moveTo((margin + dist * i) + (dist / getStepTime(currentStep) * currentStepTime), c.height / 2);
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
		
		console.log("Redrawn");
    }
	
    draw();
	
	window.addEventListener("resize",function(e){
		draw();
	});
	
    hideShowItems();

	function initWebSockets(){
		if ("WebSocket" in window) {
			var ip = $("#ipInput").val();
			var port = $("#poortInput").val();
			var wsURL = "ws://" + ip + ":" + port;
			console.log(wsURL);

		    ws = new WebSocket(wsURL);
		    ws.onopen = function(evt) { onOpen(evt) };
		    ws.onclose = function(evt) { onClose(evt) };
		    ws.onmessage = function(evt) { onMessage(evt) };
		    ws.onerror = function(evt) { onError(evt) };
    	}
	}
	
	var isOpen = false;
    
    function onOpen (evt) {
        console.log("connection opened");
		$("#ribbon").text("Online");
		$("#ribbon").removeClass("ribbon-red");$("#ribbon").addClass("ribbon-green");
		
		isOpen = true;
		sendMSG("verify");
    }
    
    function onMessage (evt){
        console.log(evt.data);
        var data = JSON.parse(evt.data);
        
        if(data.event == "washingProgramList"){
            handleWashingList(data.washingPrograms);
            populateSelectors();
        } else if(data.event == "statusUpdate"){
            handleStatusUpdate(data.washingProgram);
        } else if(data.event == "verify") {
			if(data.ok == true){
				connectHash = data.hash;
				$("#login").hide();
				$("#status").show();
				sendMSG("statusUpdate");
			}else{
				$("#login").show();
				$("#status").hide();
				ws.close();
			}
		}
        hideShowItems();
    }
    
    function onClose (evt){
		$("#ribbon").text("Offline");
		$("#ribbon").removeClass("ribbon-green");$("#ribbon").addClass("ribbon-red");
        console.log("connection closed");
		$("#login").show();
		$("#status").hide();
		isOpen = false;
    }
    
    function onError (evt){
		$("#ribbon").text("WS ERROR");
		$("#ribbon").removeClass("ribbon-green");$("#ribbon").addClass("ribbon-red");
        console.log("websocket error" + evt.data);
		isOpen = false;
    }
    
    function sendMessage() {
        ws.send(text);
    }
    
    function closeConnection() {
		sendMSG("logout");
		$("#login").show();
		$("#status").hide();
        ws.close();
    }
    
    function handleWashingList(data){
        var sel = document.getElementById('wasSelector');
        loadedWasPrograms = data;
        sel.innerHTML = "";
        for(var j = 0; j < data.length; j++) {
            sel.innerHTML += "<option id=\"j\">" + data[j].description + "</option>";
        }
        hasLoadedPrograms = true;
    }
    
    function handleStatusUpdate(data){   
        status = data["data"]["status"];
        
        var statusText = "Unknown status";
		
        switch(status){
            case 0x01:
                statusText = "Halted!";
                break;
            case 0x02:
                statusText = "Idle";
                break;
            case 0x04:
                statusText = "Running";
                break;
            case 0x08:
                statusText = "Stopped";
                break;
            case 0xFF:
                statusText = "Failed!";
                break;
        }
		
        document.getElementById("statusText").innerHTML = statusText;
        
        currentStep = parseInt(data["currentStep"]);
        timeRunning = parseInt(data["data"]["timeRunning"]);

        if(timeRunning >= getTotalTime() && (status == 0x08 || status == 0x04)){
        	var audio = new Audio('beeps.ogg');
			audio.play();
        }
		
        if(status == 4) {
            var currentDegrees = data["data"]["currentDegrees"];
            var rpm = data["data"]["currentRpm"];
            var water = data["data"]["currentWaterLevel"];
			
			if(rpm >= 128){
				rpm -= 128;
			}
			rpm *= 25;

            document.getElementById("water").innerHTML = water;
            document.getElementById("rpm").innerHTML = rpm;
            document.getElementById("temp").innerHTML = currentDegrees;
            document.getElementById("time").innerHTML = timeRunning + "/" + getTotalTime();
        } else if(hasLoadedPrograms == false){
			sendMSG("getWashingPrograms");
        }
        
        draw();
    }
    
    function hideShowItems(){
        if(status == 0x02 || status == 0x08) {
            $('#radiorpm').show();
            $('#radiotmp').show();
            $('#radiotime').show();
            $('#wasSelector').show();
            $('#start').show();
            $('#stop').hide();
        } else {
            $('#radiorpm').hide();
            $('#radiotmp').hide();
            $('#radiotime').hide(); 
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
        var rpm = data.steps[1]["rpm"];
		var time = data.steps[0]["time"];
		
		$("input[name=radiorpm][value=" + rpm + "]").prop('checked', true);
		$("input[name=radiotime][value=" + time + "]").prop('checked', true);
		$("input[name=radiotmp][value=" + currentDegrees + "]").prop('checked', true);
		
        draw();
    }

	$("#subBtn").click(function(){
		console.log($("#passInput").val().hashCode());
		initWebSockets();
		if($("#passInput").text() != ""){
			sendMSG("verify");
		}
	});
    
    $( "#start" ).click(function() {
        sendMSG("startWashingProgram");
        $('#start').hide();
        $('#wasSelector').hide();
        $('#stop').show();
    });
    
    $( "#stop" ).click(function() {
		sendMSG("stopWashingProgram");
        status = 0;
    });

	function sendMSG(event){
		if(!isOpen){
			return;
		}
		
		if(event == "startWashingProgram"){
            var data = loadedWasPrograms[$('#wasSelector')[0].selectedIndex];
			
			currentWashingProgram = {
                    "steps":[
                    {
                        "degrees": $('input[name=radiotmp]:checked').val(),
                        "rpm": data.steps[0]['rpm'].toString() ,
                        "water": data.steps[0]['water'].toString() ,
                        "time": $('input[name=radiotime]:checked').val(),
                        "rotationInterval": data.steps[0]['rotationInterval'].toString() 
                    },{
                        "degrees": data.steps[1]['degrees'].toString() ,
                        "rpm": $('input[name=radiorpm]:checked').val(),
                        "water": data.steps[1]['water'].toString() ,
                        "time": data.steps[1]['time'].toString() ,
                        "rotationInterval": data.steps[1]['rotationInterval'].toString() 
                    }               
                ]
            };
			
            var msg = {
				"event":"startWashingProgram",
				"hash":connectHash, 
				"washingProgram":currentWashingProgram
			};
		}else if(event == "stopWashingProgram") {
			var msg = { 
				"event": "stopWashingProgram",
				"hash": connectHash
			};
		} else if(event == "verify") {
			var msg = {
		        "event":"verify",
				"name": $("#nameInput").val(),
		        "password": $("#passInput").val().hashCode()
            };
		} else if(event == "logout") {
			var msg = {
		        "event":"logout",
		        "hash": connectHash
            };
		} else if(event == "getWashingPrograms") {
			var msg = {
		        "event":"getWashingPrograms",
		        "hash": connectHash
            };
		} else if(event == "statusUpdate") {
			var msg = {
		        "event":"statusUpdate",
		        "hash": connectHash
            };
		} else {
			return; /* It shouldn't send an undifined msg */
		} 
		
		console.log(msg);
		
		ws.send(JSON.stringify(msg));
	}

	String.prototype.hashCode = function() {
		var hash = 0, i, chr, len;
		
		if (this.length === 0){
			return hash;
		}
		
		for (i = 0, len = this.length; i < len; i++) {
			chr   = this.charCodeAt(i);
			hash  = ((hash << 5) - hash) + chr;
			hash |= 0;
		}
		
		return hash;
	};
});
