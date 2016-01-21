$( document ).ready(function() {

	$("#status").hide();
	$("#ipInput").val(window.location.href.replace(/.*?:\/\//g, "").replace("/", ""));
    
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

	var connectHash = "";
    
    var stepCount;
    var hasLoadedPrograms = false;
	
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
		
		console.log("Redrawn");
    }
	
    draw();
	
	window.addEventListener("resize",function(e){
		var c = document.getElementById("statusCanvas");
		c.width = $(c).width();
		c.height = $(c).height();
		draw();
	});
	
    hideShowItems();

	function initWebSockets()
	{
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
    
    function onOpen (evt) {
        console.log("connection opened");
		$(".ribbon-green").text("Online");
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
			if(data.ok == true)
			{
				connectHash = data.hash;
				$("#login").hide();
				$("#status").show();
				sendMSG("statusUpdate");
			}
			else 
			{
				$("#login").show();
				$("#status").hide();
				ws.close();
			}
		}
        hideShowItems();
    }
    
    function onClose (evt){
		$(".ribbon-green").text("Offline");
        console.log("connection closed");
		$("#login").show();
		$("#status").hide();
    }
    
    function onError (evt){
		$(".ribbon-green").text("WS ERROR");
        console.log("websocket error" + evt.data);
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
    
    function handleWashingList(data)
    {
        var sel = document.getElementById('wasSelector');
        loadedWasPrograms = data;
        sel.innerHTML = "";
        for(var j = 0; j < data.length; j++) {
            sel.innerHTML += "<option id=\"j\">" + data[j].description + "</option>";
        }
        hasLoadedPrograms = true;
    }
    
    function handleStatusUpdate(data)
    {   
        status = data["data"]["status"];
        
        var statusText = "Unknown status";
        switch(status)
        {
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
            case 0x00:
                statusText = "Failed!";
                break;
        }
        document.getElementById("statusText").innerHTML = statusText;
        
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

            document.getElementById("water").innerHTML = water;
            document.getElementById("rpm").innerHTML = rpm;
            document.getElementById("temp").innerHTML = currentDegrees;
            document.getElementById("time").innerHTML = currentStepTime + "/" + totalStepTime;
        } else if(hasLoadedPrograms == false){
			sendMSG("getWashingPrograms");
        }
        
        draw();
    }
    
    function hideShowItems()
    {
        console.log(status);
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
        var rpm = data.steps[0]["rpm"];
        var water = data.steps[0]["water"];
		var time = data.steps[0]["time"];
       
        steps = data.steps.length + 1;
        
		$("input[name=radiorpm][value=" + rpm + "]").prop('checked', true);
		$("input[name=radiotime][value=" + time + "]").prop('checked', true);
		$("input[name=radiotmp][value=" + currentDegrees + "]").prop('checked', true);

/*
        $('#waterSelector option:first-child').text(water);
        $('#rpmSelector option:first-child').text(rpm);
        $('#degreeSelector option:first-child').text(currentDegrees);
        $('#timeSelector option:first-child').text(total);
        
        $('#waterSelector option:first-child').val(water);
        $('#rpmSelector option:first-child').val(rpm);
        $('#degreeSelector option:first-child').val(currentDegrees);
        $('#timeSelector option:first-child').val(total);
        */
        $("#water").innerHTML = water;
        $("#rpm").innerHTML = rpm;
        $("#temp").innerHTML = currentDegrees;
        $("#time").innerHTML = time + " Seconde";
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

	function sendMSG(event)
	{
		if(event == "startWashingProgram")
		{
            var data = loadedWasPrograms[$('#wasSelector')[0].selectedIndex];
            var msg = {
            "event":"startWashingProgram",
            "hash":connectHash, 
            "washingProgram":{
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
                ]}
            };
            /*
            for(var i = 0; i < data['steps'].length; i++){
                msg['washingPrgram']['steps'][i]['rpm'] = data['steps'][i]['rpm'];
            }
            */
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
	  if (this.length === 0) return hash;
	  for (i = 0, len = this.length; i < len; i++) {
		chr   = this.charCodeAt(i);
		hash  = ((hash << 5) - hash) + chr;
		hash |= 0;
	  }
	  return hash;
	};
});
