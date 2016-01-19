TARGET = washingOS
LIBS = -pthread -lcrypto
CC = g++
CFLAGS = -std=c++11 -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

Base64.o: Base64.h
Door.o: Door.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Door.o: /usr/include/ucontext.h /usr/include/features.h
Door.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Door.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Door.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Door.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Door.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Door.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Door.o: UARTMessage.hpp UARTListener.hpp
Door.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Door.o: /usr/include/ucontext.h /usr/include/features.h
Door.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Door.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Door.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Door.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Door.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Door.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Door.o: UARTMessage.hpp UARTListener.hpp
HardwareComponent.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
HardwareComponent.o: libfiber.h /usr/include/ucontext.h
HardwareComponent.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareComponent.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareComponent.o: /usr/include/stdio.h /usr/include/libio.h
HardwareComponent.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareComponent.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareComponent.o: /usr/include/ctype.h /usr/include/endian.h
HardwareComponent.o: /usr/include/xlocale.h libserial.h
HardwareComponent.o: /usr/include/termios.h /usr/include/string.h
HardwareComponent.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareComponent.o: UARTListener.hpp
HardwareComponent.o: UARTInterface.hpp pRTOS.h libfiber.h
HardwareComponent.o: /usr/include/ucontext.h /usr/include/features.h
HardwareComponent.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareComponent.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareComponent.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareComponent.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareComponent.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareComponent.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
HardwareComponent.o: /usr/include/termios.h /usr/include/string.h
HardwareComponent.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareComponent.o: UARTListener.hpp
HardwareController.o: HardwareController.hpp pRTOS.h libfiber.h
HardwareController.o: /usr/include/ucontext.h /usr/include/features.h
HardwareController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareController.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareController.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareController.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareController.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareController.o: /usr/include/endian.h /usr/include/xlocale.h
HardwareController.o: HardwareListener.hpp HardwareSensor.hpp
HardwareController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
HardwareController.o: /usr/include/termios.h /usr/include/string.h
HardwareController.o: /usr/include/fcntl.h /usr/include/time.h
HardwareController.o: UARTMessage.hpp UARTListener.hpp
HardwareController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
HardwareController.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareController.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareController.o: /usr/include/stdio.h /usr/include/libio.h
HardwareController.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareController.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareController.o: /usr/include/ctype.h /usr/include/endian.h
HardwareController.o: /usr/include/xlocale.h HardwareListener.hpp
HardwareController.o: HardwareSensor.hpp HardwareComponent.hpp
HardwareController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
HardwareController.o: /usr/include/string.h /usr/include/fcntl.h
HardwareController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
HardwareListener.o: HardwareListener.hpp
HardwareSensor.o: HardwareSensor.hpp HardwareComponent.hpp UARTInterface.hpp
HardwareSensor.o: pRTOS.h libfiber.h /usr/include/ucontext.h
HardwareSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareSensor.o: /usr/include/stdio.h /usr/include/libio.h
HardwareSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareSensor.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareSensor.o: /usr/include/ctype.h /usr/include/endian.h
HardwareSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
HardwareSensor.o: /usr/include/string.h /usr/include/fcntl.h
HardwareSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
HardwareSensor.o: HardwareListener.hpp
HardwareSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
HardwareSensor.o: /usr/include/ucontext.h /usr/include/features.h
HardwareSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareSensor.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareSensor.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareSensor.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareSensor.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
HardwareSensor.o: /usr/include/termios.h /usr/include/string.h
HardwareSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareSensor.o: UARTListener.hpp HardwareListener.hpp
Heating.o: Heating.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
Heating.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
Heating.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Heating.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Heating.o: /usr/include/_G_config.h /usr/include/wchar.h
Heating.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
Heating.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
Heating.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
Heating.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
Heating.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Heating.o: /usr/include/ucontext.h /usr/include/features.h
Heating.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Heating.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Heating.o: /usr/include/_G_config.h /usr/include/wchar.h
Heating.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
Heating.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
Heating.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
Heating.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
libfiber.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
libfiber.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
libfiber.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
libfiber.o: /usr/include/_G_config.h /usr/include/wchar.h
libfiber.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
libfiber.o: /usr/include/endian.h /usr/include/xlocale.h
libfiber.o: /usr/include/string.h
libserial.o: libserial.h /usr/include/termios.h /usr/include/features.h
libserial.o: /usr/include/stdc-predef.h /usr/include/string.h
libserial.o: /usr/include/xlocale.h /usr/include/fcntl.h /usr/include/time.h
libserial.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
libserial.o: /usr/include/endian.h
Logger.o: Logger.hpp
main.o: pRTOS.h libfiber.h /usr/include/ucontext.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
main.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
main.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
main.o: /usr/include/xlocale.h UARTInterface.hpp libserial.h
main.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
main.o: /usr/include/time.h UARTMessage.hpp Door.hpp HardwareComponent.hpp
main.o: UARTListener.hpp Heating.hpp TemperatureSensor.hpp HardwareSensor.hpp
main.o: HardwareListener.hpp Motor.hpp RotationSensor.hpp Pump.hpp Tap.hpp
main.o: WaterLevelSensor.hpp SignalLed.hpp SoapTray.hpp WashingMachine.hpp
main.o: WashingMachineStatusSensor.hpp RotationController.hpp
main.o: HardwareController.hpp TemperatureController.hpp
main.o: WebInterfaceController.hpp SocketServer.hpp PracticalSocket.h
main.o: /usr/include/netdb.h /usr/include/netinet/in.h /usr/include/stdint.h
main.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h WebSocket.h
main.o: WebSocketMulticaster.h SocketMessage.hpp rapidjson/document.h
main.o: rapidjson/reader.h rapidjson/rapidjson.h /usr/include/inttypes.h
main.o: rapidjson/allocators.h rapidjson/encodings.h
main.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
main.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
main.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
main.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
main.o: rapidjson/internal/pow10.h rapidjson/error/error.h
main.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
main.o: rapidjson/writer.h rapidjson/internal/dtoa.h
main.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
main.o: rapidjson/stringbuffer.h WebServer.hpp WashingProgramController.hpp
main.o: WashingProgram.hpp WashingProgramStep.hpp WashingProgramScheduler.hpp
main.o: WaterLevelController.hpp WashingProgramStatus.hpp
main.o: WashingMachineStatus.hpp
Motor.o: Motor.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Motor.o: /usr/include/ucontext.h /usr/include/features.h
Motor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Motor.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Motor.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Motor.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Motor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Motor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Motor.o: UARTMessage.hpp UARTListener.hpp /usr/include/assert.h
Motor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Motor.o: /usr/include/ucontext.h /usr/include/features.h
Motor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Motor.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Motor.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Motor.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Motor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Motor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Motor.o: UARTMessage.hpp UARTListener.hpp
PracticalSocket.o: PracticalSocket.h /usr/include/netdb.h
PracticalSocket.o: /usr/include/features.h /usr/include/stdc-predef.h
PracticalSocket.o: /usr/include/netinet/in.h /usr/include/stdint.h
PracticalSocket.o: /usr/include/endian.h /usr/include/rpc/netdb.h
PracticalSocket.o: /usr/include/arpa/inet.h /usr/include/unistd.h
PracticalSocket.o: /usr/include/getopt.h /usr/include/ctype.h
PracticalSocket.o: /usr/include/xlocale.h /usr/include/stdio.h
PracticalSocket.o: /usr/include/libio.h /usr/include/_G_config.h
PracticalSocket.o: /usr/include/wchar.h /usr/include/errno.h
PracticalSocket.o: /usr/include/signal.h /usr/include/time.h
pRTOS.o: /usr/include/string.h /usr/include/features.h
pRTOS.o: /usr/include/stdc-predef.h /usr/include/xlocale.h
pRTOS.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
pRTOS.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
pRTOS.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/stdlib.h
pRTOS.o: /usr/include/alloca.h /usr/include/signal.h /usr/include/time.h
pRTOS.o: /usr/include/sched.h /usr/include/pthread.h pRTOS.h libfiber.h
pRTOS.o: /usr/include/ucontext.h
Pump.o: Pump.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Pump.o: /usr/include/ucontext.h /usr/include/features.h
Pump.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Pump.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Pump.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Pump.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Pump.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Pump.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Pump.o: UARTMessage.hpp UARTListener.hpp
Pump.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Pump.o: /usr/include/ucontext.h /usr/include/features.h
Pump.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Pump.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Pump.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Pump.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Pump.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Pump.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Pump.o: UARTMessage.hpp UARTListener.hpp
RotationController.o: RotationController.hpp HardwareController.hpp pRTOS.h
RotationController.o: libfiber.h /usr/include/ucontext.h
RotationController.o: /usr/include/features.h /usr/include/stdc-predef.h
RotationController.o: /usr/include/stdlib.h /usr/include/alloca.h
RotationController.o: /usr/include/stdio.h /usr/include/libio.h
RotationController.o: /usr/include/_G_config.h /usr/include/wchar.h
RotationController.o: /usr/include/unistd.h /usr/include/getopt.h
RotationController.o: /usr/include/ctype.h /usr/include/endian.h
RotationController.o: /usr/include/xlocale.h HardwareListener.hpp
RotationController.o: HardwareSensor.hpp HardwareComponent.hpp
RotationController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
RotationController.o: /usr/include/string.h /usr/include/fcntl.h
RotationController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
RotationController.o: Motor.hpp
RotationController.o: HardwareController.hpp pRTOS.h libfiber.h
RotationController.o: /usr/include/ucontext.h /usr/include/features.h
RotationController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
RotationController.o: /usr/include/alloca.h /usr/include/stdio.h
RotationController.o: /usr/include/libio.h /usr/include/_G_config.h
RotationController.o: /usr/include/wchar.h /usr/include/unistd.h
RotationController.o: /usr/include/getopt.h /usr/include/ctype.h
RotationController.o: /usr/include/endian.h /usr/include/xlocale.h
RotationController.o: HardwareListener.hpp HardwareSensor.hpp
RotationController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
RotationController.o: /usr/include/termios.h /usr/include/string.h
RotationController.o: /usr/include/fcntl.h /usr/include/time.h
RotationController.o: UARTMessage.hpp UARTListener.hpp Motor.hpp
RotationSensor.o: RotationSensor.hpp HardwareSensor.hpp HardwareComponent.hpp
RotationSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
RotationSensor.o: /usr/include/ucontext.h /usr/include/features.h
RotationSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
RotationSensor.o: /usr/include/alloca.h /usr/include/stdio.h
RotationSensor.o: /usr/include/libio.h /usr/include/_G_config.h
RotationSensor.o: /usr/include/wchar.h /usr/include/unistd.h
RotationSensor.o: /usr/include/getopt.h /usr/include/ctype.h
RotationSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
RotationSensor.o: /usr/include/termios.h /usr/include/string.h
RotationSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
RotationSensor.o: UARTListener.hpp HardwareListener.hpp
RotationSensor.o: HardwareSensor.hpp HardwareComponent.hpp UARTInterface.hpp
RotationSensor.o: pRTOS.h libfiber.h /usr/include/ucontext.h
RotationSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
RotationSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
RotationSensor.o: /usr/include/stdio.h /usr/include/libio.h
RotationSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
RotationSensor.o: /usr/include/unistd.h /usr/include/getopt.h
RotationSensor.o: /usr/include/ctype.h /usr/include/endian.h
RotationSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
RotationSensor.o: /usr/include/string.h /usr/include/fcntl.h
RotationSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
RotationSensor.o: HardwareListener.hpp
SignalLed.o: SignalLed.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
SignalLed.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
SignalLed.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SignalLed.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SignalLed.o: /usr/include/_G_config.h /usr/include/wchar.h
SignalLed.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SignalLed.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SignalLed.o: /usr/include/termios.h /usr/include/string.h
SignalLed.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
SignalLed.o: UARTListener.hpp
SignalLed.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
SignalLed.o: /usr/include/ucontext.h /usr/include/features.h
SignalLed.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SignalLed.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SignalLed.o: /usr/include/_G_config.h /usr/include/wchar.h
SignalLed.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SignalLed.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SignalLed.o: /usr/include/termios.h /usr/include/string.h
SignalLed.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
SignalLed.o: UARTListener.hpp
SoapTray.o: SoapTray.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
SoapTray.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
SoapTray.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SoapTray.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SoapTray.o: /usr/include/_G_config.h /usr/include/wchar.h
SoapTray.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SoapTray.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SoapTray.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
SoapTray.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
SoapTray.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
SoapTray.o: /usr/include/ucontext.h /usr/include/features.h
SoapTray.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SoapTray.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SoapTray.o: /usr/include/_G_config.h /usr/include/wchar.h
SoapTray.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SoapTray.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SoapTray.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
SoapTray.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
SocketMessage.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketMessage.o: rapidjson/rapidjson.h /usr/include/stdint.h
SocketMessage.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketMessage.o: /usr/include/inttypes.h /usr/include/endian.h
SocketMessage.o: rapidjson/allocators.h rapidjson/encodings.h
SocketMessage.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketMessage.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketMessage.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketMessage.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketMessage.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketMessage.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketMessage.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketMessage.o: rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/document.h rapidjson/reader.h
SocketMessage.o: rapidjson/rapidjson.h /usr/include/stdint.h
SocketMessage.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketMessage.o: /usr/include/inttypes.h /usr/include/endian.h
SocketMessage.o: rapidjson/allocators.h rapidjson/encodings.h
SocketMessage.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketMessage.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketMessage.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketMessage.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketMessage.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketMessage.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketMessage.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketMessage.o: rapidjson/stringbuffer.h
SocketServer.o: SocketServer.hpp PracticalSocket.h /usr/include/netdb.h
SocketServer.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
SocketServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
SocketServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
SocketServer.o: /usr/include/getopt.h /usr/include/ctype.h
SocketServer.o: /usr/include/xlocale.h /usr/include/stdio.h
SocketServer.o: /usr/include/libio.h /usr/include/_G_config.h
SocketServer.o: /usr/include/wchar.h WebSocket.h WebSocketMulticaster.h
SocketServer.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketServer.o: rapidjson/rapidjson.h /usr/include/inttypes.h
SocketServer.o: rapidjson/allocators.h rapidjson/encodings.h
SocketServer.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketServer.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketServer.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketServer.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketServer.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketServer.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketServer.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketServer.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketServer.o: rapidjson/stringbuffer.h
SocketServer.o: PracticalSocket.h /usr/include/netdb.h
SocketServer.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
SocketServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
SocketServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
SocketServer.o: /usr/include/getopt.h /usr/include/ctype.h
SocketServer.o: /usr/include/xlocale.h /usr/include/stdio.h
SocketServer.o: /usr/include/libio.h /usr/include/_G_config.h
SocketServer.o: /usr/include/wchar.h WebSocket.h WebSocketMulticaster.h
SocketServer.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketServer.o: rapidjson/rapidjson.h /usr/include/inttypes.h
SocketServer.o: rapidjson/allocators.h rapidjson/encodings.h
SocketServer.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketServer.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketServer.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketServer.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketServer.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketServer.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketServer.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketServer.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketServer.o: rapidjson/stringbuffer.h
Tap.o: Tap.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Tap.o: /usr/include/ucontext.h /usr/include/features.h
Tap.o: /usr/include/stdc-predef.h /usr/include/stdlib.h /usr/include/alloca.h
Tap.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Tap.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
Tap.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/xlocale.h
Tap.o: libserial.h /usr/include/termios.h /usr/include/string.h
Tap.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
Tap.o: UARTListener.hpp
Tap.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Tap.o: /usr/include/ucontext.h /usr/include/features.h
Tap.o: /usr/include/stdc-predef.h /usr/include/stdlib.h /usr/include/alloca.h
Tap.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Tap.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
Tap.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/xlocale.h
Tap.o: libserial.h /usr/include/termios.h /usr/include/string.h
Tap.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
Tap.o: UARTListener.hpp
TemperatureController.o: TemperatureController.hpp HardwareController.hpp
TemperatureController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
TemperatureController.o: /usr/include/features.h /usr/include/stdc-predef.h
TemperatureController.o: /usr/include/stdlib.h /usr/include/alloca.h
TemperatureController.o: /usr/include/stdio.h /usr/include/libio.h
TemperatureController.o: /usr/include/_G_config.h /usr/include/wchar.h
TemperatureController.o: /usr/include/unistd.h /usr/include/getopt.h
TemperatureController.o: /usr/include/ctype.h /usr/include/endian.h
TemperatureController.o: /usr/include/xlocale.h HardwareListener.hpp
TemperatureController.o: HardwareSensor.hpp HardwareComponent.hpp
TemperatureController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
TemperatureController.o: /usr/include/string.h /usr/include/fcntl.h
TemperatureController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
TemperatureController.o: Heating.hpp
TemperatureController.o: HardwareController.hpp pRTOS.h libfiber.h
TemperatureController.o: /usr/include/ucontext.h /usr/include/features.h
TemperatureController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
TemperatureController.o: /usr/include/alloca.h /usr/include/stdio.h
TemperatureController.o: /usr/include/libio.h /usr/include/_G_config.h
TemperatureController.o: /usr/include/wchar.h /usr/include/unistd.h
TemperatureController.o: /usr/include/getopt.h /usr/include/ctype.h
TemperatureController.o: /usr/include/endian.h /usr/include/xlocale.h
TemperatureController.o: HardwareListener.hpp HardwareSensor.hpp
TemperatureController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
TemperatureController.o: /usr/include/termios.h /usr/include/string.h
TemperatureController.o: /usr/include/fcntl.h /usr/include/time.h
TemperatureController.o: UARTMessage.hpp UARTListener.hpp Heating.hpp
TemperatureSensor.o: TemperatureSensor.hpp HardwareSensor.hpp
TemperatureSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
TemperatureSensor.o: libfiber.h /usr/include/ucontext.h
TemperatureSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
TemperatureSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
TemperatureSensor.o: /usr/include/stdio.h /usr/include/libio.h
TemperatureSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
TemperatureSensor.o: /usr/include/unistd.h /usr/include/getopt.h
TemperatureSensor.o: /usr/include/ctype.h /usr/include/endian.h
TemperatureSensor.o: /usr/include/xlocale.h libserial.h
TemperatureSensor.o: /usr/include/termios.h /usr/include/string.h
TemperatureSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
TemperatureSensor.o: UARTListener.hpp HardwareListener.hpp
TemperatureSensor.o: HardwareSensor.hpp HardwareComponent.hpp
TemperatureSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
TemperatureSensor.o: /usr/include/ucontext.h /usr/include/features.h
TemperatureSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
TemperatureSensor.o: /usr/include/alloca.h /usr/include/stdio.h
TemperatureSensor.o: /usr/include/libio.h /usr/include/_G_config.h
TemperatureSensor.o: /usr/include/wchar.h /usr/include/unistd.h
TemperatureSensor.o: /usr/include/getopt.h /usr/include/ctype.h
TemperatureSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
TemperatureSensor.o: /usr/include/termios.h /usr/include/string.h
TemperatureSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
TemperatureSensor.o: UARTListener.hpp HardwareListener.hpp
UARTInterface.o: UARTInterface.hpp pRTOS.h libfiber.h /usr/include/ucontext.h
UARTInterface.o: /usr/include/features.h /usr/include/stdc-predef.h
UARTInterface.o: /usr/include/stdlib.h /usr/include/alloca.h
UARTInterface.o: /usr/include/stdio.h /usr/include/libio.h
UARTInterface.o: /usr/include/_G_config.h /usr/include/wchar.h
UARTInterface.o: /usr/include/unistd.h /usr/include/getopt.h
UARTInterface.o: /usr/include/ctype.h /usr/include/endian.h
UARTInterface.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
UARTInterface.o: /usr/include/string.h /usr/include/fcntl.h
UARTInterface.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
UARTInterface.o: pRTOS.h libfiber.h /usr/include/ucontext.h
UARTInterface.o: /usr/include/features.h /usr/include/stdc-predef.h
UARTInterface.o: /usr/include/stdlib.h /usr/include/alloca.h
UARTInterface.o: /usr/include/stdio.h /usr/include/libio.h
UARTInterface.o: /usr/include/_G_config.h /usr/include/wchar.h
UARTInterface.o: /usr/include/unistd.h /usr/include/getopt.h
UARTInterface.o: /usr/include/ctype.h /usr/include/endian.h
UARTInterface.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
UARTInterface.o: /usr/include/string.h /usr/include/fcntl.h
UARTInterface.o: /usr/include/time.h UARTInterface.hpp UARTMessage.hpp
UARTListener.o: UARTListener.hpp UARTMessage.hpp
UARTListener.o: UARTMessage.hpp
UARTMessage.o: UARTMessage.hpp
WashingMachine.o: WashingMachine.hpp HardwareComponent.hpp UARTInterface.hpp
WashingMachine.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingMachine.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingMachine.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachine.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachine.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachine.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachine.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachine.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
WashingMachine.o: /usr/include/string.h /usr/include/fcntl.h
WashingMachine.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WashingMachine.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
WashingMachine.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachine.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingMachine.o: /usr/include/alloca.h /usr/include/stdio.h
WashingMachine.o: /usr/include/libio.h /usr/include/_G_config.h
WashingMachine.o: /usr/include/wchar.h /usr/include/unistd.h
WashingMachine.o: /usr/include/getopt.h /usr/include/ctype.h
WashingMachine.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
WashingMachine.o: /usr/include/termios.h /usr/include/string.h
WashingMachine.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
WashingMachine.o: UARTListener.hpp
WashingMachineStatusSensor.o: WashingMachineStatusSensor.hpp
WashingMachineStatusSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WashingMachineStatusSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WashingMachineStatusSensor.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachineStatusSensor.o: /usr/include/stdc-predef.h
WashingMachineStatusSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachineStatusSensor.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachineStatusSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachineStatusSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachineStatusSensor.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachineStatusSensor.o: /usr/include/xlocale.h libserial.h
WashingMachineStatusSensor.o: /usr/include/termios.h /usr/include/string.h
WashingMachineStatusSensor.o: /usr/include/fcntl.h /usr/include/time.h
WashingMachineStatusSensor.o: UARTMessage.hpp UARTListener.hpp
WashingMachineStatusSensor.o: HardwareListener.hpp
WashingMachineStatusSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WashingMachineStatusSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WashingMachineStatusSensor.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachineStatusSensor.o: /usr/include/stdc-predef.h
WashingMachineStatusSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachineStatusSensor.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachineStatusSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachineStatusSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachineStatusSensor.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachineStatusSensor.o: /usr/include/xlocale.h libserial.h
WashingMachineStatusSensor.o: /usr/include/termios.h /usr/include/string.h
WashingMachineStatusSensor.o: /usr/include/fcntl.h /usr/include/time.h
WashingMachineStatusSensor.o: UARTMessage.hpp UARTListener.hpp
WashingMachineStatusSensor.o: HardwareListener.hpp
WashingProgramController.o: WashingProgramController.hpp pRTOS.h libfiber.h
WashingProgramController.o: /usr/include/ucontext.h /usr/include/features.h
WashingProgramController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramController.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramController.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramController.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramController.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramController.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramController.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramController.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramController.o: WaterLevelController.hpp HardwareController.hpp
WashingProgramController.o: HardwareListener.hpp HardwareSensor.hpp
WashingProgramController.o: HardwareComponent.hpp UARTInterface.hpp
WashingProgramController.o: libserial.h /usr/include/termios.h
WashingProgramController.o: /usr/include/string.h /usr/include/fcntl.h
WashingProgramController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WashingProgramController.o: RotationController.hpp Motor.hpp
WashingProgramController.o: TemperatureController.hpp Heating.hpp Door.hpp
WashingProgramController.o: SignalLed.hpp WashingMachine.hpp
WashingProgramController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingProgramController.o: /usr/include/features.h
WashingProgramController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramController.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramController.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramController.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramController.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramController.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramController.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramController.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramController.o: WaterLevelController.hpp HardwareController.hpp
WashingProgramController.o: HardwareListener.hpp HardwareSensor.hpp
WashingProgramController.o: HardwareComponent.hpp UARTInterface.hpp
WashingProgramController.o: libserial.h /usr/include/termios.h
WashingProgramController.o: /usr/include/string.h /usr/include/fcntl.h
WashingProgramController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WashingProgramController.o: RotationController.hpp Motor.hpp
WashingProgramController.o: TemperatureController.hpp Heating.hpp Door.hpp
WashingProgramController.o: SignalLed.hpp WashingMachine.hpp
WashingProgram.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgram.o: WashingProgramStep.hpp
WashingProgramScheduler.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramScheduler.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingProgramScheduler.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingProgramScheduler.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingProgramScheduler.o: /usr/include/stdio.h /usr/include/libio.h
WashingProgramScheduler.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingProgramScheduler.o: /usr/include/unistd.h /usr/include/getopt.h
WashingProgramScheduler.o: /usr/include/ctype.h /usr/include/endian.h
WashingProgramScheduler.o: /usr/include/xlocale.h WashingProgram.hpp
WashingProgramScheduler.o: WashingProgramStep.hpp
WashingProgramScheduler.o: /usr/include/time.h pRTOS.h libfiber.h
WashingProgramScheduler.o: /usr/include/ucontext.h /usr/include/features.h
WashingProgramScheduler.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramScheduler.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramScheduler.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramScheduler.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramScheduler.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramScheduler.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramScheduler.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramStatus.o: WashingProgramStatus.hpp SocketMessage.hpp
WashingProgramStatus.o: rapidjson/document.h rapidjson/reader.h
WashingProgramStatus.o: rapidjson/rapidjson.h /usr/include/stdint.h
WashingProgramStatus.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingProgramStatus.o: /usr/include/inttypes.h /usr/include/endian.h
WashingProgramStatus.o: rapidjson/allocators.h rapidjson/encodings.h
WashingProgramStatus.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
WashingProgramStatus.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
WashingProgramStatus.o: rapidjson/internal/strtod.h
WashingProgramStatus.o: rapidjson/internal/ieee754.h
WashingProgramStatus.o: rapidjson/internal/biginteger.h
WashingProgramStatus.o: rapidjson/internal/diyfp.h rapidjson/internal/pow10.h
WashingProgramStatus.o: rapidjson/error/error.h rapidjson/internal/strfunc.h
WashingProgramStatus.o: rapidjson/stringbuffer.h rapidjson/writer.h
WashingProgramStatus.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WashingProgramStatus.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WashingProgramStatus.o: WashingMachineStatus.hpp
WashingProgramStatus.o: SocketMessage.hpp rapidjson/document.h
WashingProgramStatus.o: rapidjson/reader.h rapidjson/rapidjson.h
WashingProgramStatus.o: /usr/include/stdint.h /usr/include/features.h
WashingProgramStatus.o: /usr/include/stdc-predef.h /usr/include/inttypes.h
WashingProgramStatus.o: /usr/include/endian.h rapidjson/allocators.h
WashingProgramStatus.o: rapidjson/encodings.h rapidjson/internal/meta.h
WashingProgramStatus.o: rapidjson/rapidjson.h rapidjson/internal/stack.h
WashingProgramStatus.o: rapidjson/internal/swap.h rapidjson/internal/strtod.h
WashingProgramStatus.o: rapidjson/internal/ieee754.h
WashingProgramStatus.o: rapidjson/internal/biginteger.h
WashingProgramStatus.o: rapidjson/internal/diyfp.h rapidjson/internal/pow10.h
WashingProgramStatus.o: rapidjson/error/error.h rapidjson/internal/strfunc.h
WashingProgramStatus.o: rapidjson/stringbuffer.h rapidjson/writer.h
WashingProgramStatus.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WashingProgramStatus.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WashingProgramStatus.o: WashingMachineStatus.hpp
WashingProgramStep.o: WashingProgramStep.hpp
WaterLevelController.o: WaterLevelController.hpp HardwareController.hpp
WaterLevelController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WaterLevelController.o: /usr/include/features.h /usr/include/stdc-predef.h
WaterLevelController.o: /usr/include/stdlib.h /usr/include/alloca.h
WaterLevelController.o: /usr/include/stdio.h /usr/include/libio.h
WaterLevelController.o: /usr/include/_G_config.h /usr/include/wchar.h
WaterLevelController.o: /usr/include/unistd.h /usr/include/getopt.h
WaterLevelController.o: /usr/include/ctype.h /usr/include/endian.h
WaterLevelController.o: /usr/include/xlocale.h HardwareListener.hpp
WaterLevelController.o: HardwareSensor.hpp HardwareComponent.hpp
WaterLevelController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
WaterLevelController.o: /usr/include/string.h /usr/include/fcntl.h
WaterLevelController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WaterLevelController.o: Pump.hpp Tap.hpp
WaterLevelController.o: HardwareController.hpp pRTOS.h libfiber.h
WaterLevelController.o: /usr/include/ucontext.h /usr/include/features.h
WaterLevelController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WaterLevelController.o: /usr/include/alloca.h /usr/include/stdio.h
WaterLevelController.o: /usr/include/libio.h /usr/include/_G_config.h
WaterLevelController.o: /usr/include/wchar.h /usr/include/unistd.h
WaterLevelController.o: /usr/include/getopt.h /usr/include/ctype.h
WaterLevelController.o: /usr/include/endian.h /usr/include/xlocale.h
WaterLevelController.o: HardwareListener.hpp HardwareSensor.hpp
WaterLevelController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WaterLevelController.o: /usr/include/termios.h /usr/include/string.h
WaterLevelController.o: /usr/include/fcntl.h /usr/include/time.h
WaterLevelController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WaterLevelSensor.o: WaterLevelSensor.hpp HardwareSensor.hpp
WaterLevelSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
WaterLevelSensor.o: libfiber.h /usr/include/ucontext.h
WaterLevelSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
WaterLevelSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WaterLevelSensor.o: /usr/include/stdio.h /usr/include/libio.h
WaterLevelSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WaterLevelSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WaterLevelSensor.o: /usr/include/ctype.h /usr/include/endian.h
WaterLevelSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
WaterLevelSensor.o: /usr/include/string.h /usr/include/fcntl.h
WaterLevelSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WaterLevelSensor.o: HardwareListener.hpp
WaterLevelSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WaterLevelSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WaterLevelSensor.o: /usr/include/ucontext.h /usr/include/features.h
WaterLevelSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WaterLevelSensor.o: /usr/include/alloca.h /usr/include/stdio.h
WaterLevelSensor.o: /usr/include/libio.h /usr/include/_G_config.h
WaterLevelSensor.o: /usr/include/wchar.h /usr/include/unistd.h
WaterLevelSensor.o: /usr/include/getopt.h /usr/include/ctype.h
WaterLevelSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
WaterLevelSensor.o: /usr/include/termios.h /usr/include/string.h
WaterLevelSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
WaterLevelSensor.o: UARTListener.hpp HardwareListener.hpp
WebInterfaceController.o: WebInterfaceController.hpp pRTOS.h libfiber.h
WebInterfaceController.o: /usr/include/ucontext.h /usr/include/features.h
WebInterfaceController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WebInterfaceController.o: /usr/include/alloca.h /usr/include/stdio.h
WebInterfaceController.o: /usr/include/libio.h /usr/include/_G_config.h
WebInterfaceController.o: /usr/include/wchar.h /usr/include/unistd.h
WebInterfaceController.o: /usr/include/getopt.h /usr/include/ctype.h
WebInterfaceController.o: /usr/include/endian.h /usr/include/xlocale.h
WebInterfaceController.o: SocketServer.hpp PracticalSocket.h
WebInterfaceController.o: /usr/include/netdb.h /usr/include/netinet/in.h
WebInterfaceController.o: /usr/include/stdint.h /usr/include/rpc/netdb.h
WebInterfaceController.o: /usr/include/arpa/inet.h WebSocket.h
WebInterfaceController.o: WebSocketMulticaster.h SocketMessage.hpp
WebInterfaceController.o: rapidjson/document.h rapidjson/reader.h
WebInterfaceController.o: rapidjson/rapidjson.h /usr/include/inttypes.h
WebInterfaceController.o: rapidjson/allocators.h rapidjson/encodings.h
WebInterfaceController.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
WebInterfaceController.o: rapidjson/internal/stack.h
WebInterfaceController.o: rapidjson/internal/swap.h
WebInterfaceController.o: rapidjson/internal/strtod.h
WebInterfaceController.o: rapidjson/internal/ieee754.h
WebInterfaceController.o: rapidjson/internal/biginteger.h
WebInterfaceController.o: rapidjson/internal/diyfp.h
WebInterfaceController.o: rapidjson/internal/pow10.h rapidjson/error/error.h
WebInterfaceController.o: rapidjson/internal/strfunc.h
WebInterfaceController.o: rapidjson/stringbuffer.h rapidjson/writer.h
WebInterfaceController.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WebInterfaceController.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WebInterfaceController.o: WebServer.hpp WashingProgramController.hpp
WebInterfaceController.o: WashingProgram.hpp WashingProgramStep.hpp
WebInterfaceController.o: WashingProgramScheduler.hpp /usr/include/time.h
WebInterfaceController.o: WaterLevelController.hpp HardwareController.hpp
WebInterfaceController.o: HardwareListener.hpp HardwareSensor.hpp
WebInterfaceController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WebInterfaceController.o: /usr/include/termios.h /usr/include/string.h
WebInterfaceController.o: /usr/include/fcntl.h UARTMessage.hpp
WebInterfaceController.o: UARTListener.hpp Pump.hpp Tap.hpp
WebInterfaceController.o: RotationController.hpp Motor.hpp
WebInterfaceController.o: TemperatureController.hpp Heating.hpp Door.hpp
WebInterfaceController.o: SignalLed.hpp WashingMachine.hpp
WebInterfaceController.o: WashingProgramStatus.hpp WashingMachineStatus.hpp
WebInterfaceController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WebInterfaceController.o: /usr/include/features.h /usr/include/stdc-predef.h
WebInterfaceController.o: /usr/include/stdlib.h /usr/include/alloca.h
WebInterfaceController.o: /usr/include/stdio.h /usr/include/libio.h
WebInterfaceController.o: /usr/include/_G_config.h /usr/include/wchar.h
WebInterfaceController.o: /usr/include/unistd.h /usr/include/getopt.h
WebInterfaceController.o: /usr/include/ctype.h /usr/include/endian.h
WebInterfaceController.o: /usr/include/xlocale.h SocketServer.hpp
WebInterfaceController.o: PracticalSocket.h /usr/include/netdb.h
WebInterfaceController.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebInterfaceController.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebInterfaceController.o: WebSocket.h WebSocketMulticaster.h
WebInterfaceController.o: SocketMessage.hpp rapidjson/document.h
WebInterfaceController.o: rapidjson/reader.h rapidjson/rapidjson.h
WebInterfaceController.o: /usr/include/inttypes.h rapidjson/allocators.h
WebInterfaceController.o: rapidjson/encodings.h rapidjson/internal/meta.h
WebInterfaceController.o: rapidjson/rapidjson.h rapidjson/internal/stack.h
WebInterfaceController.o: rapidjson/internal/swap.h
WebInterfaceController.o: rapidjson/internal/strtod.h
WebInterfaceController.o: rapidjson/internal/ieee754.h
WebInterfaceController.o: rapidjson/internal/biginteger.h
WebInterfaceController.o: rapidjson/internal/diyfp.h
WebInterfaceController.o: rapidjson/internal/pow10.h rapidjson/error/error.h
WebInterfaceController.o: rapidjson/internal/strfunc.h
WebInterfaceController.o: rapidjson/stringbuffer.h rapidjson/writer.h
WebInterfaceController.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WebInterfaceController.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WebInterfaceController.o: WebServer.hpp WashingProgramController.hpp
WebInterfaceController.o: WashingProgram.hpp WashingProgramStep.hpp
WebInterfaceController.o: WashingProgramScheduler.hpp /usr/include/time.h
WebInterfaceController.o: WaterLevelController.hpp HardwareController.hpp
WebInterfaceController.o: HardwareListener.hpp HardwareSensor.hpp
WebInterfaceController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WebInterfaceController.o: /usr/include/termios.h /usr/include/string.h
WebInterfaceController.o: /usr/include/fcntl.h UARTMessage.hpp
WebInterfaceController.o: UARTListener.hpp Pump.hpp Tap.hpp
WebInterfaceController.o: RotationController.hpp Motor.hpp
WebInterfaceController.o: TemperatureController.hpp Heating.hpp Door.hpp
WebInterfaceController.o: SignalLed.hpp WashingMachine.hpp
WebInterfaceController.o: WashingProgramStatus.hpp WashingMachineStatus.hpp
WebServer.o: WebServer.hpp PracticalSocket.h /usr/include/netdb.h
WebServer.o: /usr/include/features.h /usr/include/stdc-predef.h
WebServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServer.o: /usr/include/getopt.h /usr/include/ctype.h
WebServer.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebServer.o: /usr/include/_G_config.h /usr/include/wchar.h Logger.hpp
WebServer.o: WebServerGetHandler.hpp WebServerResponseHandler.hpp
WebServerGetHandler.o: WebServerGetHandler.hpp
WebServer.o: PracticalSocket.h /usr/include/netdb.h /usr/include/features.h
WebServer.o: /usr/include/stdc-predef.h /usr/include/netinet/in.h
WebServer.o: /usr/include/stdint.h /usr/include/endian.h
WebServer.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebServer.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
WebServer.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebServer.o: /usr/include/_G_config.h /usr/include/wchar.h
WebServerResponseHandler.o: WebServerResponseHandler.hpp PracticalSocket.h
WebServerResponseHandler.o: /usr/include/netdb.h /usr/include/features.h
WebServerResponseHandler.o: /usr/include/stdc-predef.h
WebServerResponseHandler.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServerResponseHandler.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServerResponseHandler.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServerResponseHandler.o: /usr/include/getopt.h /usr/include/ctype.h
WebServerResponseHandler.o: /usr/include/xlocale.h /usr/include/stdio.h
WebServerResponseHandler.o: /usr/include/libio.h /usr/include/_G_config.h
WebServerResponseHandler.o: /usr/include/wchar.h Logger.hpp
WebServerResponseHandler.o: PracticalSocket.h /usr/include/netdb.h
WebServerResponseHandler.o: /usr/include/features.h
WebServerResponseHandler.o: /usr/include/stdc-predef.h
WebServerResponseHandler.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServerResponseHandler.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServerResponseHandler.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServerResponseHandler.o: /usr/include/getopt.h /usr/include/ctype.h
WebServerResponseHandler.o: /usr/include/xlocale.h /usr/include/stdio.h
WebServerResponseHandler.o: /usr/include/libio.h /usr/include/_G_config.h
WebServerResponseHandler.o: /usr/include/wchar.h Logger.hpp
WebSocket.o: WebSocket.h PracticalSocket.h /usr/include/netdb.h
WebSocket.o: /usr/include/features.h /usr/include/stdc-predef.h
WebSocket.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebSocket.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebSocket.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebSocket.o: /usr/include/getopt.h /usr/include/ctype.h
WebSocket.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebSocket.o: /usr/include/_G_config.h /usr/include/wchar.h
WebSocket.o: /usr/include/openssl/sha.h /usr/include/openssl/e_os2.h Base64.h
WebSocketMulticaster.o: WebSocketMulticaster.h WebSocket.h PracticalSocket.h
WebSocketMulticaster.o: /usr/include/netdb.h /usr/include/features.h
WebSocketMulticaster.o: /usr/include/stdc-predef.h /usr/include/netinet/in.h
WebSocketMulticaster.o: /usr/include/stdint.h /usr/include/endian.h
WebSocketMulticaster.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebSocketMulticaster.o: /usr/include/unistd.h /usr/include/getopt.h
WebSocketMulticaster.o: /usr/include/ctype.h /usr/include/xlocale.h
WebSocketMulticaster.o: /usr/include/stdio.h /usr/include/libio.h
WebSocketMulticaster.o: /usr/include/_G_config.h /usr/include/wchar.h
# DO NOT DELETE

Base64.o: Base64.h
Door.o: Door.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Door.o: /usr/include/ucontext.h /usr/include/features.h
Door.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Door.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Door.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Door.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Door.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Door.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Door.o: UARTMessage.hpp UARTListener.hpp
Door.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Door.o: /usr/include/ucontext.h /usr/include/features.h
Door.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Door.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Door.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Door.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Door.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Door.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Door.o: UARTMessage.hpp UARTListener.hpp
DoorSensor.o: DoorSensor.hpp HardwareSensor.hpp HardwareComponent.hpp
DoorSensor.o: UARTInterface.hpp pRTOS.h libfiber.h /usr/include/ucontext.h
DoorSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
DoorSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
DoorSensor.o: /usr/include/stdio.h /usr/include/libio.h
DoorSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
DoorSensor.o: /usr/include/unistd.h /usr/include/getopt.h
DoorSensor.o: /usr/include/ctype.h /usr/include/endian.h
DoorSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
DoorSensor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
DoorSensor.o: UARTMessage.hpp UARTListener.hpp HardwareListener.hpp
DoorSensor.o: HardwareSensor.hpp HardwareComponent.hpp UARTInterface.hpp
DoorSensor.o: pRTOS.h libfiber.h /usr/include/ucontext.h
DoorSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
DoorSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
DoorSensor.o: /usr/include/stdio.h /usr/include/libio.h
DoorSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
DoorSensor.o: /usr/include/unistd.h /usr/include/getopt.h
DoorSensor.o: /usr/include/ctype.h /usr/include/endian.h
DoorSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
DoorSensor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
DoorSensor.o: UARTMessage.hpp UARTListener.hpp HardwareListener.hpp
HardwareComponent.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
HardwareComponent.o: libfiber.h /usr/include/ucontext.h
HardwareComponent.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareComponent.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareComponent.o: /usr/include/stdio.h /usr/include/libio.h
HardwareComponent.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareComponent.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareComponent.o: /usr/include/ctype.h /usr/include/endian.h
HardwareComponent.o: /usr/include/xlocale.h libserial.h
HardwareComponent.o: /usr/include/termios.h /usr/include/string.h
HardwareComponent.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareComponent.o: UARTListener.hpp
HardwareComponent.o: UARTInterface.hpp pRTOS.h libfiber.h
HardwareComponent.o: /usr/include/ucontext.h /usr/include/features.h
HardwareComponent.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareComponent.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareComponent.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareComponent.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareComponent.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareComponent.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
HardwareComponent.o: /usr/include/termios.h /usr/include/string.h
HardwareComponent.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareComponent.o: UARTListener.hpp
HardwareController.o: HardwareController.hpp pRTOS.h libfiber.h
HardwareController.o: /usr/include/ucontext.h /usr/include/features.h
HardwareController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareController.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareController.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareController.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareController.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareController.o: /usr/include/endian.h /usr/include/xlocale.h
HardwareController.o: HardwareListener.hpp HardwareSensor.hpp
HardwareController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
HardwareController.o: /usr/include/termios.h /usr/include/string.h
HardwareController.o: /usr/include/fcntl.h /usr/include/time.h
HardwareController.o: UARTMessage.hpp UARTListener.hpp
HardwareController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
HardwareController.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareController.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareController.o: /usr/include/stdio.h /usr/include/libio.h
HardwareController.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareController.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareController.o: /usr/include/ctype.h /usr/include/endian.h
HardwareController.o: /usr/include/xlocale.h HardwareListener.hpp
HardwareController.o: HardwareSensor.hpp HardwareComponent.hpp
HardwareController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
HardwareController.o: /usr/include/string.h /usr/include/fcntl.h
HardwareController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
HardwareListener.o: HardwareListener.hpp
HardwareSensor.o: HardwareSensor.hpp HardwareComponent.hpp UARTInterface.hpp
HardwareSensor.o: pRTOS.h libfiber.h /usr/include/ucontext.h
HardwareSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
HardwareSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
HardwareSensor.o: /usr/include/stdio.h /usr/include/libio.h
HardwareSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
HardwareSensor.o: /usr/include/unistd.h /usr/include/getopt.h
HardwareSensor.o: /usr/include/ctype.h /usr/include/endian.h
HardwareSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
HardwareSensor.o: /usr/include/string.h /usr/include/fcntl.h
HardwareSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
HardwareSensor.o: HardwareListener.hpp
HardwareSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
HardwareSensor.o: /usr/include/ucontext.h /usr/include/features.h
HardwareSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
HardwareSensor.o: /usr/include/alloca.h /usr/include/stdio.h
HardwareSensor.o: /usr/include/libio.h /usr/include/_G_config.h
HardwareSensor.o: /usr/include/wchar.h /usr/include/unistd.h
HardwareSensor.o: /usr/include/getopt.h /usr/include/ctype.h
HardwareSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
HardwareSensor.o: /usr/include/termios.h /usr/include/string.h
HardwareSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
HardwareSensor.o: UARTListener.hpp HardwareListener.hpp
Heating.o: Heating.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
Heating.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
Heating.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Heating.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Heating.o: /usr/include/_G_config.h /usr/include/wchar.h
Heating.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
Heating.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
Heating.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
Heating.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
Heating.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Heating.o: /usr/include/ucontext.h /usr/include/features.h
Heating.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Heating.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Heating.o: /usr/include/_G_config.h /usr/include/wchar.h
Heating.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
Heating.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
Heating.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
Heating.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
libfiber.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
libfiber.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
libfiber.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
libfiber.o: /usr/include/_G_config.h /usr/include/wchar.h
libfiber.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
libfiber.o: /usr/include/endian.h /usr/include/xlocale.h
libfiber.o: /usr/include/string.h
libserial.o: libserial.h /usr/include/termios.h /usr/include/features.h
libserial.o: /usr/include/stdc-predef.h /usr/include/string.h
libserial.o: /usr/include/xlocale.h /usr/include/fcntl.h /usr/include/time.h
libserial.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
libserial.o: /usr/include/endian.h
Logger.o: Logger.hpp
main.o: pRTOS.h libfiber.h /usr/include/ucontext.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
main.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
main.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
main.o: /usr/include/xlocale.h UARTInterface.hpp libserial.h
main.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
main.o: /usr/include/time.h UARTMessage.hpp Door.hpp HardwareComponent.hpp
main.o: UARTListener.hpp Heating.hpp TemperatureSensor.hpp HardwareSensor.hpp
main.o: HardwareListener.hpp Motor.hpp RotationSensor.hpp Pump.hpp Tap.hpp
main.o: WaterLevelSensor.hpp SignalLed.hpp SoapTray.hpp WashingMachine.hpp
main.o: WashingMachineStatusSensor.hpp RotationController.hpp
main.o: HardwareController.hpp TemperatureController.hpp
main.o: WebInterfaceController.hpp SocketServer.hpp PracticalSocket.h
main.o: /usr/include/netdb.h /usr/include/netinet/in.h /usr/include/stdint.h
main.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h WebSocket.h
main.o: WebSocketMulticaster.h SocketMessage.hpp rapidjson/document.h
main.o: rapidjson/reader.h rapidjson/rapidjson.h /usr/include/inttypes.h
main.o: rapidjson/allocators.h rapidjson/encodings.h
main.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
main.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
main.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
main.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
main.o: rapidjson/internal/pow10.h rapidjson/error/error.h
main.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
main.o: rapidjson/writer.h rapidjson/internal/dtoa.h
main.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
main.o: rapidjson/stringbuffer.h WebServer.hpp WashingProgramController.hpp
main.o: WashingProgram.hpp WashingProgramStep.hpp WashingProgramScheduler.hpp
main.o: WaterLevelController.hpp WashingProgramStatus.hpp
main.o: WashingMachineStatus.hpp DoorSensor.hpp
Motor.o: Motor.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Motor.o: /usr/include/ucontext.h /usr/include/features.h
Motor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Motor.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Motor.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Motor.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Motor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Motor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Motor.o: UARTMessage.hpp UARTListener.hpp /usr/include/assert.h
Motor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Motor.o: /usr/include/ucontext.h /usr/include/features.h
Motor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Motor.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Motor.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Motor.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Motor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Motor.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Motor.o: UARTMessage.hpp UARTListener.hpp
PracticalSocket.o: PracticalSocket.h /usr/include/netdb.h
PracticalSocket.o: /usr/include/features.h /usr/include/stdc-predef.h
PracticalSocket.o: /usr/include/netinet/in.h /usr/include/stdint.h
PracticalSocket.o: /usr/include/endian.h /usr/include/rpc/netdb.h
PracticalSocket.o: /usr/include/arpa/inet.h /usr/include/unistd.h
PracticalSocket.o: /usr/include/getopt.h /usr/include/ctype.h
PracticalSocket.o: /usr/include/xlocale.h /usr/include/stdio.h
PracticalSocket.o: /usr/include/libio.h /usr/include/_G_config.h
PracticalSocket.o: /usr/include/wchar.h /usr/include/errno.h
PracticalSocket.o: /usr/include/signal.h /usr/include/time.h
pRTOS.o: /usr/include/string.h /usr/include/features.h
pRTOS.o: /usr/include/stdc-predef.h /usr/include/xlocale.h
pRTOS.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
pRTOS.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
pRTOS.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/stdlib.h
pRTOS.o: /usr/include/alloca.h /usr/include/signal.h /usr/include/time.h
pRTOS.o: /usr/include/sched.h /usr/include/pthread.h pRTOS.h libfiber.h
pRTOS.o: /usr/include/ucontext.h
Pump.o: Pump.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Pump.o: /usr/include/ucontext.h /usr/include/features.h
Pump.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Pump.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Pump.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Pump.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Pump.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Pump.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Pump.o: UARTMessage.hpp UARTListener.hpp
Pump.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Pump.o: /usr/include/ucontext.h /usr/include/features.h
Pump.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
Pump.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
Pump.o: /usr/include/_G_config.h /usr/include/wchar.h /usr/include/unistd.h
Pump.o: /usr/include/getopt.h /usr/include/ctype.h /usr/include/endian.h
Pump.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
Pump.o: /usr/include/string.h /usr/include/fcntl.h /usr/include/time.h
Pump.o: UARTMessage.hpp UARTListener.hpp
RotationController.o: RotationController.hpp HardwareController.hpp pRTOS.h
RotationController.o: libfiber.h /usr/include/ucontext.h
RotationController.o: /usr/include/features.h /usr/include/stdc-predef.h
RotationController.o: /usr/include/stdlib.h /usr/include/alloca.h
RotationController.o: /usr/include/stdio.h /usr/include/libio.h
RotationController.o: /usr/include/_G_config.h /usr/include/wchar.h
RotationController.o: /usr/include/unistd.h /usr/include/getopt.h
RotationController.o: /usr/include/ctype.h /usr/include/endian.h
RotationController.o: /usr/include/xlocale.h HardwareListener.hpp
RotationController.o: HardwareSensor.hpp HardwareComponent.hpp
RotationController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
RotationController.o: /usr/include/string.h /usr/include/fcntl.h
RotationController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
RotationController.o: Motor.hpp
RotationController.o: HardwareController.hpp pRTOS.h libfiber.h
RotationController.o: /usr/include/ucontext.h /usr/include/features.h
RotationController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
RotationController.o: /usr/include/alloca.h /usr/include/stdio.h
RotationController.o: /usr/include/libio.h /usr/include/_G_config.h
RotationController.o: /usr/include/wchar.h /usr/include/unistd.h
RotationController.o: /usr/include/getopt.h /usr/include/ctype.h
RotationController.o: /usr/include/endian.h /usr/include/xlocale.h
RotationController.o: HardwareListener.hpp HardwareSensor.hpp
RotationController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
RotationController.o: /usr/include/termios.h /usr/include/string.h
RotationController.o: /usr/include/fcntl.h /usr/include/time.h
RotationController.o: UARTMessage.hpp UARTListener.hpp Motor.hpp
RotationSensor.o: RotationSensor.hpp HardwareSensor.hpp HardwareComponent.hpp
RotationSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
RotationSensor.o: /usr/include/ucontext.h /usr/include/features.h
RotationSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
RotationSensor.o: /usr/include/alloca.h /usr/include/stdio.h
RotationSensor.o: /usr/include/libio.h /usr/include/_G_config.h
RotationSensor.o: /usr/include/wchar.h /usr/include/unistd.h
RotationSensor.o: /usr/include/getopt.h /usr/include/ctype.h
RotationSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
RotationSensor.o: /usr/include/termios.h /usr/include/string.h
RotationSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
RotationSensor.o: UARTListener.hpp HardwareListener.hpp
RotationSensor.o: HardwareSensor.hpp HardwareComponent.hpp UARTInterface.hpp
RotationSensor.o: pRTOS.h libfiber.h /usr/include/ucontext.h
RotationSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
RotationSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
RotationSensor.o: /usr/include/stdio.h /usr/include/libio.h
RotationSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
RotationSensor.o: /usr/include/unistd.h /usr/include/getopt.h
RotationSensor.o: /usr/include/ctype.h /usr/include/endian.h
RotationSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
RotationSensor.o: /usr/include/string.h /usr/include/fcntl.h
RotationSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
RotationSensor.o: HardwareListener.hpp
SignalLed.o: SignalLed.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
SignalLed.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
SignalLed.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SignalLed.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SignalLed.o: /usr/include/_G_config.h /usr/include/wchar.h
SignalLed.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SignalLed.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SignalLed.o: /usr/include/termios.h /usr/include/string.h
SignalLed.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
SignalLed.o: UARTListener.hpp
SignalLed.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
SignalLed.o: /usr/include/ucontext.h /usr/include/features.h
SignalLed.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SignalLed.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SignalLed.o: /usr/include/_G_config.h /usr/include/wchar.h
SignalLed.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SignalLed.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SignalLed.o: /usr/include/termios.h /usr/include/string.h
SignalLed.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
SignalLed.o: UARTListener.hpp
SoapTray.o: SoapTray.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h
SoapTray.o: libfiber.h /usr/include/ucontext.h /usr/include/features.h
SoapTray.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SoapTray.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SoapTray.o: /usr/include/_G_config.h /usr/include/wchar.h
SoapTray.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SoapTray.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SoapTray.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
SoapTray.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
SoapTray.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
SoapTray.o: /usr/include/ucontext.h /usr/include/features.h
SoapTray.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
SoapTray.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
SoapTray.o: /usr/include/_G_config.h /usr/include/wchar.h
SoapTray.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
SoapTray.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
SoapTray.o: /usr/include/termios.h /usr/include/string.h /usr/include/fcntl.h
SoapTray.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
SocketMessage.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketMessage.o: rapidjson/rapidjson.h /usr/include/stdint.h
SocketMessage.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketMessage.o: /usr/include/inttypes.h /usr/include/endian.h
SocketMessage.o: rapidjson/allocators.h rapidjson/encodings.h
SocketMessage.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketMessage.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketMessage.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketMessage.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketMessage.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketMessage.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketMessage.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketMessage.o: rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/document.h rapidjson/reader.h
SocketMessage.o: rapidjson/rapidjson.h /usr/include/stdint.h
SocketMessage.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketMessage.o: /usr/include/inttypes.h /usr/include/endian.h
SocketMessage.o: rapidjson/allocators.h rapidjson/encodings.h
SocketMessage.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketMessage.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketMessage.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketMessage.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketMessage.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketMessage.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketMessage.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketMessage.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketMessage.o: rapidjson/stringbuffer.h
SocketServer.o: SocketServer.hpp PracticalSocket.h /usr/include/netdb.h
SocketServer.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
SocketServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
SocketServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
SocketServer.o: /usr/include/getopt.h /usr/include/ctype.h
SocketServer.o: /usr/include/xlocale.h /usr/include/stdio.h
SocketServer.o: /usr/include/libio.h /usr/include/_G_config.h
SocketServer.o: /usr/include/wchar.h WebSocket.h WebSocketMulticaster.h
SocketServer.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketServer.o: rapidjson/rapidjson.h /usr/include/inttypes.h
SocketServer.o: rapidjson/allocators.h rapidjson/encodings.h
SocketServer.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketServer.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketServer.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketServer.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketServer.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketServer.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketServer.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketServer.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketServer.o: rapidjson/stringbuffer.h
SocketServer.o: PracticalSocket.h /usr/include/netdb.h
SocketServer.o: /usr/include/features.h /usr/include/stdc-predef.h
SocketServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
SocketServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
SocketServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
SocketServer.o: /usr/include/getopt.h /usr/include/ctype.h
SocketServer.o: /usr/include/xlocale.h /usr/include/stdio.h
SocketServer.o: /usr/include/libio.h /usr/include/_G_config.h
SocketServer.o: /usr/include/wchar.h WebSocket.h WebSocketMulticaster.h
SocketServer.o: SocketMessage.hpp rapidjson/document.h rapidjson/reader.h
SocketServer.o: rapidjson/rapidjson.h /usr/include/inttypes.h
SocketServer.o: rapidjson/allocators.h rapidjson/encodings.h
SocketServer.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
SocketServer.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
SocketServer.o: rapidjson/internal/strtod.h rapidjson/internal/ieee754.h
SocketServer.o: rapidjson/internal/biginteger.h rapidjson/internal/diyfp.h
SocketServer.o: rapidjson/internal/pow10.h rapidjson/error/error.h
SocketServer.o: rapidjson/internal/strfunc.h rapidjson/stringbuffer.h
SocketServer.o: rapidjson/writer.h rapidjson/internal/dtoa.h
SocketServer.o: rapidjson/internal/itoa.h rapidjson/internal/itoa.h
SocketServer.o: rapidjson/stringbuffer.h
Tap.o: Tap.hpp HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Tap.o: /usr/include/ucontext.h /usr/include/features.h
Tap.o: /usr/include/stdc-predef.h /usr/include/stdlib.h /usr/include/alloca.h
Tap.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Tap.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
Tap.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/xlocale.h
Tap.o: libserial.h /usr/include/termios.h /usr/include/string.h
Tap.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
Tap.o: UARTListener.hpp
Tap.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
Tap.o: /usr/include/ucontext.h /usr/include/features.h
Tap.o: /usr/include/stdc-predef.h /usr/include/stdlib.h /usr/include/alloca.h
Tap.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Tap.o: /usr/include/wchar.h /usr/include/unistd.h /usr/include/getopt.h
Tap.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/xlocale.h
Tap.o: libserial.h /usr/include/termios.h /usr/include/string.h
Tap.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
Tap.o: UARTListener.hpp
TemperatureController.o: TemperatureController.hpp HardwareController.hpp
TemperatureController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
TemperatureController.o: /usr/include/features.h /usr/include/stdc-predef.h
TemperatureController.o: /usr/include/stdlib.h /usr/include/alloca.h
TemperatureController.o: /usr/include/stdio.h /usr/include/libio.h
TemperatureController.o: /usr/include/_G_config.h /usr/include/wchar.h
TemperatureController.o: /usr/include/unistd.h /usr/include/getopt.h
TemperatureController.o: /usr/include/ctype.h /usr/include/endian.h
TemperatureController.o: /usr/include/xlocale.h HardwareListener.hpp
TemperatureController.o: HardwareSensor.hpp HardwareComponent.hpp
TemperatureController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
TemperatureController.o: /usr/include/string.h /usr/include/fcntl.h
TemperatureController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
TemperatureController.o: Heating.hpp
TemperatureController.o: HardwareController.hpp pRTOS.h libfiber.h
TemperatureController.o: /usr/include/ucontext.h /usr/include/features.h
TemperatureController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
TemperatureController.o: /usr/include/alloca.h /usr/include/stdio.h
TemperatureController.o: /usr/include/libio.h /usr/include/_G_config.h
TemperatureController.o: /usr/include/wchar.h /usr/include/unistd.h
TemperatureController.o: /usr/include/getopt.h /usr/include/ctype.h
TemperatureController.o: /usr/include/endian.h /usr/include/xlocale.h
TemperatureController.o: HardwareListener.hpp HardwareSensor.hpp
TemperatureController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
TemperatureController.o: /usr/include/termios.h /usr/include/string.h
TemperatureController.o: /usr/include/fcntl.h /usr/include/time.h
TemperatureController.o: UARTMessage.hpp UARTListener.hpp Heating.hpp
TemperatureSensor.o: TemperatureSensor.hpp HardwareSensor.hpp
TemperatureSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
TemperatureSensor.o: libfiber.h /usr/include/ucontext.h
TemperatureSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
TemperatureSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
TemperatureSensor.o: /usr/include/stdio.h /usr/include/libio.h
TemperatureSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
TemperatureSensor.o: /usr/include/unistd.h /usr/include/getopt.h
TemperatureSensor.o: /usr/include/ctype.h /usr/include/endian.h
TemperatureSensor.o: /usr/include/xlocale.h libserial.h
TemperatureSensor.o: /usr/include/termios.h /usr/include/string.h
TemperatureSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
TemperatureSensor.o: UARTListener.hpp HardwareListener.hpp
TemperatureSensor.o: HardwareSensor.hpp HardwareComponent.hpp
TemperatureSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
TemperatureSensor.o: /usr/include/ucontext.h /usr/include/features.h
TemperatureSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
TemperatureSensor.o: /usr/include/alloca.h /usr/include/stdio.h
TemperatureSensor.o: /usr/include/libio.h /usr/include/_G_config.h
TemperatureSensor.o: /usr/include/wchar.h /usr/include/unistd.h
TemperatureSensor.o: /usr/include/getopt.h /usr/include/ctype.h
TemperatureSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
TemperatureSensor.o: /usr/include/termios.h /usr/include/string.h
TemperatureSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
TemperatureSensor.o: UARTListener.hpp HardwareListener.hpp
UARTInterface.o: UARTInterface.hpp pRTOS.h libfiber.h /usr/include/ucontext.h
UARTInterface.o: /usr/include/features.h /usr/include/stdc-predef.h
UARTInterface.o: /usr/include/stdlib.h /usr/include/alloca.h
UARTInterface.o: /usr/include/stdio.h /usr/include/libio.h
UARTInterface.o: /usr/include/_G_config.h /usr/include/wchar.h
UARTInterface.o: /usr/include/unistd.h /usr/include/getopt.h
UARTInterface.o: /usr/include/ctype.h /usr/include/endian.h
UARTInterface.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
UARTInterface.o: /usr/include/string.h /usr/include/fcntl.h
UARTInterface.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
UARTInterface.o: /usr/include/errno.h
UARTInterface.o: pRTOS.h libfiber.h /usr/include/ucontext.h
UARTInterface.o: /usr/include/features.h /usr/include/stdc-predef.h
UARTInterface.o: /usr/include/stdlib.h /usr/include/alloca.h
UARTInterface.o: /usr/include/stdio.h /usr/include/libio.h
UARTInterface.o: /usr/include/_G_config.h /usr/include/wchar.h
UARTInterface.o: /usr/include/unistd.h /usr/include/getopt.h
UARTInterface.o: /usr/include/ctype.h /usr/include/endian.h
UARTInterface.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
UARTInterface.o: /usr/include/string.h /usr/include/fcntl.h
UARTInterface.o: /usr/include/time.h UARTInterface.hpp UARTMessage.hpp
UARTListener.o: UARTListener.hpp UARTMessage.hpp
UARTListener.o: UARTMessage.hpp
UARTMessage.o: UARTMessage.hpp
WashingMachine.o: WashingMachine.hpp HardwareComponent.hpp UARTInterface.hpp
WashingMachine.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingMachine.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingMachine.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachine.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachine.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachine.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachine.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachine.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
WashingMachine.o: /usr/include/string.h /usr/include/fcntl.h
WashingMachine.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WashingMachine.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h libfiber.h
WashingMachine.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachine.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingMachine.o: /usr/include/alloca.h /usr/include/stdio.h
WashingMachine.o: /usr/include/libio.h /usr/include/_G_config.h
WashingMachine.o: /usr/include/wchar.h /usr/include/unistd.h
WashingMachine.o: /usr/include/getopt.h /usr/include/ctype.h
WashingMachine.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
WashingMachine.o: /usr/include/termios.h /usr/include/string.h
WashingMachine.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
WashingMachine.o: UARTListener.hpp
WashingMachineStatusSensor.o: WashingMachineStatusSensor.hpp
WashingMachineStatusSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WashingMachineStatusSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WashingMachineStatusSensor.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachineStatusSensor.o: /usr/include/stdc-predef.h
WashingMachineStatusSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachineStatusSensor.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachineStatusSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachineStatusSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachineStatusSensor.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachineStatusSensor.o: /usr/include/xlocale.h libserial.h
WashingMachineStatusSensor.o: /usr/include/termios.h /usr/include/string.h
WashingMachineStatusSensor.o: /usr/include/fcntl.h /usr/include/time.h
WashingMachineStatusSensor.o: UARTMessage.hpp UARTListener.hpp
WashingMachineStatusSensor.o: HardwareListener.hpp
WashingMachineStatusSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WashingMachineStatusSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WashingMachineStatusSensor.o: /usr/include/ucontext.h /usr/include/features.h
WashingMachineStatusSensor.o: /usr/include/stdc-predef.h
WashingMachineStatusSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingMachineStatusSensor.o: /usr/include/stdio.h /usr/include/libio.h
WashingMachineStatusSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingMachineStatusSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WashingMachineStatusSensor.o: /usr/include/ctype.h /usr/include/endian.h
WashingMachineStatusSensor.o: /usr/include/xlocale.h libserial.h
WashingMachineStatusSensor.o: /usr/include/termios.h /usr/include/string.h
WashingMachineStatusSensor.o: /usr/include/fcntl.h /usr/include/time.h
WashingMachineStatusSensor.o: UARTMessage.hpp UARTListener.hpp
WashingMachineStatusSensor.o: HardwareListener.hpp
WashingProgramController.o: WashingProgramController.hpp pRTOS.h libfiber.h
WashingProgramController.o: /usr/include/ucontext.h /usr/include/features.h
WashingProgramController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramController.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramController.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramController.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramController.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramController.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramController.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramController.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramController.o: WaterLevelController.hpp HardwareController.hpp
WashingProgramController.o: HardwareListener.hpp HardwareSensor.hpp
WashingProgramController.o: HardwareComponent.hpp UARTInterface.hpp
WashingProgramController.o: libserial.h /usr/include/termios.h
WashingProgramController.o: /usr/include/string.h /usr/include/fcntl.h
WashingProgramController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WashingProgramController.o: RotationController.hpp Motor.hpp
WashingProgramController.o: TemperatureController.hpp Heating.hpp Door.hpp
WashingProgramController.o: SignalLed.hpp WashingMachine.hpp SoapTray.hpp
WashingProgramController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingProgramController.o: /usr/include/features.h
WashingProgramController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramController.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramController.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramController.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramController.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramController.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramController.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramController.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramController.o: WaterLevelController.hpp HardwareController.hpp
WashingProgramController.o: HardwareListener.hpp HardwareSensor.hpp
WashingProgramController.o: HardwareComponent.hpp UARTInterface.hpp
WashingProgramController.o: libserial.h /usr/include/termios.h
WashingProgramController.o: /usr/include/string.h /usr/include/fcntl.h
WashingProgramController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WashingProgramController.o: RotationController.hpp Motor.hpp
WashingProgramController.o: TemperatureController.hpp Heating.hpp Door.hpp
WashingProgramController.o: SignalLed.hpp WashingMachine.hpp SoapTray.hpp
WashingProgram.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgram.o: WashingProgramStep.hpp
WashingProgramScheduler.o: WashingProgramScheduler.hpp /usr/include/time.h
WashingProgramScheduler.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WashingProgramScheduler.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingProgramScheduler.o: /usr/include/stdlib.h /usr/include/alloca.h
WashingProgramScheduler.o: /usr/include/stdio.h /usr/include/libio.h
WashingProgramScheduler.o: /usr/include/_G_config.h /usr/include/wchar.h
WashingProgramScheduler.o: /usr/include/unistd.h /usr/include/getopt.h
WashingProgramScheduler.o: /usr/include/ctype.h /usr/include/endian.h
WashingProgramScheduler.o: /usr/include/xlocale.h WashingProgram.hpp
WashingProgramScheduler.o: WashingProgramStep.hpp
WashingProgramScheduler.o: /usr/include/time.h pRTOS.h libfiber.h
WashingProgramScheduler.o: /usr/include/ucontext.h /usr/include/features.h
WashingProgramScheduler.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WashingProgramScheduler.o: /usr/include/alloca.h /usr/include/stdio.h
WashingProgramScheduler.o: /usr/include/libio.h /usr/include/_G_config.h
WashingProgramScheduler.o: /usr/include/wchar.h /usr/include/unistd.h
WashingProgramScheduler.o: /usr/include/getopt.h /usr/include/ctype.h
WashingProgramScheduler.o: /usr/include/endian.h /usr/include/xlocale.h
WashingProgramScheduler.o: WashingProgram.hpp WashingProgramStep.hpp
WashingProgramStatus.o: WashingProgramStatus.hpp SocketMessage.hpp
WashingProgramStatus.o: rapidjson/document.h rapidjson/reader.h
WashingProgramStatus.o: rapidjson/rapidjson.h /usr/include/stdint.h
WashingProgramStatus.o: /usr/include/features.h /usr/include/stdc-predef.h
WashingProgramStatus.o: /usr/include/inttypes.h /usr/include/endian.h
WashingProgramStatus.o: rapidjson/allocators.h rapidjson/encodings.h
WashingProgramStatus.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
WashingProgramStatus.o: rapidjson/internal/stack.h rapidjson/internal/swap.h
WashingProgramStatus.o: rapidjson/internal/strtod.h
WashingProgramStatus.o: rapidjson/internal/ieee754.h
WashingProgramStatus.o: rapidjson/internal/biginteger.h
WashingProgramStatus.o: rapidjson/internal/diyfp.h rapidjson/internal/pow10.h
WashingProgramStatus.o: rapidjson/error/error.h rapidjson/internal/strfunc.h
WashingProgramStatus.o: rapidjson/stringbuffer.h rapidjson/writer.h
WashingProgramStatus.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WashingProgramStatus.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WashingProgramStatus.o: WashingMachineStatus.hpp
WashingProgramStatus.o: SocketMessage.hpp rapidjson/document.h
WashingProgramStatus.o: rapidjson/reader.h rapidjson/rapidjson.h
WashingProgramStatus.o: /usr/include/stdint.h /usr/include/features.h
WashingProgramStatus.o: /usr/include/stdc-predef.h /usr/include/inttypes.h
WashingProgramStatus.o: /usr/include/endian.h rapidjson/allocators.h
WashingProgramStatus.o: rapidjson/encodings.h rapidjson/internal/meta.h
WashingProgramStatus.o: rapidjson/rapidjson.h rapidjson/internal/stack.h
WashingProgramStatus.o: rapidjson/internal/swap.h rapidjson/internal/strtod.h
WashingProgramStatus.o: rapidjson/internal/ieee754.h
WashingProgramStatus.o: rapidjson/internal/biginteger.h
WashingProgramStatus.o: rapidjson/internal/diyfp.h rapidjson/internal/pow10.h
WashingProgramStatus.o: rapidjson/error/error.h rapidjson/internal/strfunc.h
WashingProgramStatus.o: rapidjson/stringbuffer.h rapidjson/writer.h
WashingProgramStatus.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WashingProgramStatus.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WashingProgramStatus.o: WashingMachineStatus.hpp
WashingProgramStep.o: WashingProgramStep.hpp
WaterLevelController.o: WaterLevelController.hpp HardwareController.hpp
WaterLevelController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WaterLevelController.o: /usr/include/features.h /usr/include/stdc-predef.h
WaterLevelController.o: /usr/include/stdlib.h /usr/include/alloca.h
WaterLevelController.o: /usr/include/stdio.h /usr/include/libio.h
WaterLevelController.o: /usr/include/_G_config.h /usr/include/wchar.h
WaterLevelController.o: /usr/include/unistd.h /usr/include/getopt.h
WaterLevelController.o: /usr/include/ctype.h /usr/include/endian.h
WaterLevelController.o: /usr/include/xlocale.h HardwareListener.hpp
WaterLevelController.o: HardwareSensor.hpp HardwareComponent.hpp
WaterLevelController.o: UARTInterface.hpp libserial.h /usr/include/termios.h
WaterLevelController.o: /usr/include/string.h /usr/include/fcntl.h
WaterLevelController.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WaterLevelController.o: Pump.hpp Tap.hpp
WaterLevelController.o: HardwareController.hpp pRTOS.h libfiber.h
WaterLevelController.o: /usr/include/ucontext.h /usr/include/features.h
WaterLevelController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WaterLevelController.o: /usr/include/alloca.h /usr/include/stdio.h
WaterLevelController.o: /usr/include/libio.h /usr/include/_G_config.h
WaterLevelController.o: /usr/include/wchar.h /usr/include/unistd.h
WaterLevelController.o: /usr/include/getopt.h /usr/include/ctype.h
WaterLevelController.o: /usr/include/endian.h /usr/include/xlocale.h
WaterLevelController.o: HardwareListener.hpp HardwareSensor.hpp
WaterLevelController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WaterLevelController.o: /usr/include/termios.h /usr/include/string.h
WaterLevelController.o: /usr/include/fcntl.h /usr/include/time.h
WaterLevelController.o: UARTMessage.hpp UARTListener.hpp Pump.hpp Tap.hpp
WaterLevelSensor.o: WaterLevelSensor.hpp HardwareSensor.hpp
WaterLevelSensor.o: HardwareComponent.hpp UARTInterface.hpp pRTOS.h
WaterLevelSensor.o: libfiber.h /usr/include/ucontext.h
WaterLevelSensor.o: /usr/include/features.h /usr/include/stdc-predef.h
WaterLevelSensor.o: /usr/include/stdlib.h /usr/include/alloca.h
WaterLevelSensor.o: /usr/include/stdio.h /usr/include/libio.h
WaterLevelSensor.o: /usr/include/_G_config.h /usr/include/wchar.h
WaterLevelSensor.o: /usr/include/unistd.h /usr/include/getopt.h
WaterLevelSensor.o: /usr/include/ctype.h /usr/include/endian.h
WaterLevelSensor.o: /usr/include/xlocale.h libserial.h /usr/include/termios.h
WaterLevelSensor.o: /usr/include/string.h /usr/include/fcntl.h
WaterLevelSensor.o: /usr/include/time.h UARTMessage.hpp UARTListener.hpp
WaterLevelSensor.o: HardwareListener.hpp
WaterLevelSensor.o: HardwareSensor.hpp HardwareComponent.hpp
WaterLevelSensor.o: UARTInterface.hpp pRTOS.h libfiber.h
WaterLevelSensor.o: /usr/include/ucontext.h /usr/include/features.h
WaterLevelSensor.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WaterLevelSensor.o: /usr/include/alloca.h /usr/include/stdio.h
WaterLevelSensor.o: /usr/include/libio.h /usr/include/_G_config.h
WaterLevelSensor.o: /usr/include/wchar.h /usr/include/unistd.h
WaterLevelSensor.o: /usr/include/getopt.h /usr/include/ctype.h
WaterLevelSensor.o: /usr/include/endian.h /usr/include/xlocale.h libserial.h
WaterLevelSensor.o: /usr/include/termios.h /usr/include/string.h
WaterLevelSensor.o: /usr/include/fcntl.h /usr/include/time.h UARTMessage.hpp
WaterLevelSensor.o: UARTListener.hpp HardwareListener.hpp
WebInterfaceController.o: WebInterfaceController.hpp pRTOS.h libfiber.h
WebInterfaceController.o: /usr/include/ucontext.h /usr/include/features.h
WebInterfaceController.o: /usr/include/stdc-predef.h /usr/include/stdlib.h
WebInterfaceController.o: /usr/include/alloca.h /usr/include/stdio.h
WebInterfaceController.o: /usr/include/libio.h /usr/include/_G_config.h
WebInterfaceController.o: /usr/include/wchar.h /usr/include/unistd.h
WebInterfaceController.o: /usr/include/getopt.h /usr/include/ctype.h
WebInterfaceController.o: /usr/include/endian.h /usr/include/xlocale.h
WebInterfaceController.o: SocketServer.hpp PracticalSocket.h
WebInterfaceController.o: /usr/include/netdb.h /usr/include/netinet/in.h
WebInterfaceController.o: /usr/include/stdint.h /usr/include/rpc/netdb.h
WebInterfaceController.o: /usr/include/arpa/inet.h WebSocket.h
WebInterfaceController.o: WebSocketMulticaster.h SocketMessage.hpp
WebInterfaceController.o: rapidjson/document.h rapidjson/reader.h
WebInterfaceController.o: rapidjson/rapidjson.h /usr/include/inttypes.h
WebInterfaceController.o: rapidjson/allocators.h rapidjson/encodings.h
WebInterfaceController.o: rapidjson/internal/meta.h rapidjson/rapidjson.h
WebInterfaceController.o: rapidjson/internal/stack.h
WebInterfaceController.o: rapidjson/internal/swap.h
WebInterfaceController.o: rapidjson/internal/strtod.h
WebInterfaceController.o: rapidjson/internal/ieee754.h
WebInterfaceController.o: rapidjson/internal/biginteger.h
WebInterfaceController.o: rapidjson/internal/diyfp.h
WebInterfaceController.o: rapidjson/internal/pow10.h rapidjson/error/error.h
WebInterfaceController.o: rapidjson/internal/strfunc.h
WebInterfaceController.o: rapidjson/stringbuffer.h rapidjson/writer.h
WebInterfaceController.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WebInterfaceController.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WebInterfaceController.o: WebServer.hpp WashingProgramController.hpp
WebInterfaceController.o: WashingProgram.hpp WashingProgramStep.hpp
WebInterfaceController.o: WashingProgramScheduler.hpp /usr/include/time.h
WebInterfaceController.o: WaterLevelController.hpp HardwareController.hpp
WebInterfaceController.o: HardwareListener.hpp HardwareSensor.hpp
WebInterfaceController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WebInterfaceController.o: /usr/include/termios.h /usr/include/string.h
WebInterfaceController.o: /usr/include/fcntl.h UARTMessage.hpp
WebInterfaceController.o: UARTListener.hpp Pump.hpp Tap.hpp
WebInterfaceController.o: RotationController.hpp Motor.hpp
WebInterfaceController.o: TemperatureController.hpp Heating.hpp Door.hpp
WebInterfaceController.o: SignalLed.hpp WashingMachine.hpp SoapTray.hpp
WebInterfaceController.o: WashingProgramStatus.hpp WashingMachineStatus.hpp
WebInterfaceController.o: pRTOS.h libfiber.h /usr/include/ucontext.h
WebInterfaceController.o: /usr/include/features.h /usr/include/stdc-predef.h
WebInterfaceController.o: /usr/include/stdlib.h /usr/include/alloca.h
WebInterfaceController.o: /usr/include/stdio.h /usr/include/libio.h
WebInterfaceController.o: /usr/include/_G_config.h /usr/include/wchar.h
WebInterfaceController.o: /usr/include/unistd.h /usr/include/getopt.h
WebInterfaceController.o: /usr/include/ctype.h /usr/include/endian.h
WebInterfaceController.o: /usr/include/xlocale.h SocketServer.hpp
WebInterfaceController.o: PracticalSocket.h /usr/include/netdb.h
WebInterfaceController.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebInterfaceController.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebInterfaceController.o: WebSocket.h WebSocketMulticaster.h
WebInterfaceController.o: SocketMessage.hpp rapidjson/document.h
WebInterfaceController.o: rapidjson/reader.h rapidjson/rapidjson.h
WebInterfaceController.o: /usr/include/inttypes.h rapidjson/allocators.h
WebInterfaceController.o: rapidjson/encodings.h rapidjson/internal/meta.h
WebInterfaceController.o: rapidjson/rapidjson.h rapidjson/internal/stack.h
WebInterfaceController.o: rapidjson/internal/swap.h
WebInterfaceController.o: rapidjson/internal/strtod.h
WebInterfaceController.o: rapidjson/internal/ieee754.h
WebInterfaceController.o: rapidjson/internal/biginteger.h
WebInterfaceController.o: rapidjson/internal/diyfp.h
WebInterfaceController.o: rapidjson/internal/pow10.h rapidjson/error/error.h
WebInterfaceController.o: rapidjson/internal/strfunc.h
WebInterfaceController.o: rapidjson/stringbuffer.h rapidjson/writer.h
WebInterfaceController.o: rapidjson/internal/dtoa.h rapidjson/internal/itoa.h
WebInterfaceController.o: rapidjson/internal/itoa.h rapidjson/stringbuffer.h
WebInterfaceController.o: WebServer.hpp WashingProgramController.hpp
WebInterfaceController.o: WashingProgram.hpp WashingProgramStep.hpp
WebInterfaceController.o: WashingProgramScheduler.hpp /usr/include/time.h
WebInterfaceController.o: WaterLevelController.hpp HardwareController.hpp
WebInterfaceController.o: HardwareListener.hpp HardwareSensor.hpp
WebInterfaceController.o: HardwareComponent.hpp UARTInterface.hpp libserial.h
WebInterfaceController.o: /usr/include/termios.h /usr/include/string.h
WebInterfaceController.o: /usr/include/fcntl.h UARTMessage.hpp
WebInterfaceController.o: UARTListener.hpp Pump.hpp Tap.hpp
WebInterfaceController.o: RotationController.hpp Motor.hpp
WebInterfaceController.o: TemperatureController.hpp Heating.hpp Door.hpp
WebInterfaceController.o: SignalLed.hpp WashingMachine.hpp SoapTray.hpp
WebInterfaceController.o: WashingProgramStatus.hpp WashingMachineStatus.hpp
WebServer.o: WebServer.hpp PracticalSocket.h /usr/include/netdb.h
WebServer.o: /usr/include/features.h /usr/include/stdc-predef.h
WebServer.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServer.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServer.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServer.o: /usr/include/getopt.h /usr/include/ctype.h
WebServer.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebServer.o: /usr/include/_G_config.h /usr/include/wchar.h Logger.hpp
WebServer.o: WebServerGetHandler.hpp WebServerResponseHandler.hpp
WebServerGetHandler.o: WebServerGetHandler.hpp
WebServer.o: PracticalSocket.h /usr/include/netdb.h /usr/include/features.h
WebServer.o: /usr/include/stdc-predef.h /usr/include/netinet/in.h
WebServer.o: /usr/include/stdint.h /usr/include/endian.h
WebServer.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebServer.o: /usr/include/unistd.h /usr/include/getopt.h /usr/include/ctype.h
WebServer.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebServer.o: /usr/include/_G_config.h /usr/include/wchar.h
WebServerResponseHandler.o: WebServerResponseHandler.hpp PracticalSocket.h
WebServerResponseHandler.o: /usr/include/netdb.h /usr/include/features.h
WebServerResponseHandler.o: /usr/include/stdc-predef.h
WebServerResponseHandler.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServerResponseHandler.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServerResponseHandler.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServerResponseHandler.o: /usr/include/getopt.h /usr/include/ctype.h
WebServerResponseHandler.o: /usr/include/xlocale.h /usr/include/stdio.h
WebServerResponseHandler.o: /usr/include/libio.h /usr/include/_G_config.h
WebServerResponseHandler.o: /usr/include/wchar.h Logger.hpp
WebServerResponseHandler.o: PracticalSocket.h /usr/include/netdb.h
WebServerResponseHandler.o: /usr/include/features.h
WebServerResponseHandler.o: /usr/include/stdc-predef.h
WebServerResponseHandler.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebServerResponseHandler.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebServerResponseHandler.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebServerResponseHandler.o: /usr/include/getopt.h /usr/include/ctype.h
WebServerResponseHandler.o: /usr/include/xlocale.h /usr/include/stdio.h
WebServerResponseHandler.o: /usr/include/libio.h /usr/include/_G_config.h
WebServerResponseHandler.o: /usr/include/wchar.h Logger.hpp
WebSocket.o: WebSocket.h PracticalSocket.h /usr/include/netdb.h
WebSocket.o: /usr/include/features.h /usr/include/stdc-predef.h
WebSocket.o: /usr/include/netinet/in.h /usr/include/stdint.h
WebSocket.o: /usr/include/endian.h /usr/include/rpc/netdb.h
WebSocket.o: /usr/include/arpa/inet.h /usr/include/unistd.h
WebSocket.o: /usr/include/getopt.h /usr/include/ctype.h
WebSocket.o: /usr/include/xlocale.h /usr/include/stdio.h /usr/include/libio.h
WebSocket.o: /usr/include/_G_config.h /usr/include/wchar.h
WebSocket.o: /usr/include/openssl/sha.h /usr/include/openssl/e_os2.h Base64.h
WebSocketMulticaster.o: WebSocketMulticaster.h WebSocket.h PracticalSocket.h
WebSocketMulticaster.o: /usr/include/netdb.h /usr/include/features.h
WebSocketMulticaster.o: /usr/include/stdc-predef.h /usr/include/netinet/in.h
WebSocketMulticaster.o: /usr/include/stdint.h /usr/include/endian.h
WebSocketMulticaster.o: /usr/include/rpc/netdb.h /usr/include/arpa/inet.h
WebSocketMulticaster.o: /usr/include/unistd.h /usr/include/getopt.h
WebSocketMulticaster.o: /usr/include/ctype.h /usr/include/xlocale.h
WebSocketMulticaster.o: /usr/include/stdio.h /usr/include/libio.h
WebSocketMulticaster.o: /usr/include/_G_config.h /usr/include/wchar.h
