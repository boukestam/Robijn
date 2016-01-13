int main(){
	UARTInterface* uartInterface = new UARTInterface();

	Door* door = new Door(uartInterface);
	
	Heating* heating = new Heating(uartInterface);
	TemperatureSensor* temperatureSensor = new TemperatureSensor(uartInterface);
	
	Motor* motor = new Motor(uartInterface);
	RotationSensor* sensor = new RotationSensor(uartInterface);
	
	Pump* pump = new Pump(uartInterface);
	Tap* tap = new Tap(uartInterface);
	WaterLevelSensor* waterLevelSensor = new WaterLevelSensor(uartInterface);
	
	SignalLed* led = new SignalLed(uartInterface);
	
	SoapTray* soapTray = new SoapTray(uartInterface);
	
	WashingMachine* washingMachine = new WashingMachine(uartInterface);
	WashingMachineStatusSensor* washingMachineStatusSensor = new WashingMachineStatusSensor(uartInterface);
	
	RotationController* rotationController = new RotationController();
	TemperatureController* temperatureController = new TemperatureController();
	WebInterfaceController* webInterfaceController = new WebInterfaceController();
	
	WashingProgramController* washingProgramController = new WashingProgramController();
	WaterLevelController* waterLevelController = new WaterLevelController();
	
	RTOS::run();
	
	return 0;
}
