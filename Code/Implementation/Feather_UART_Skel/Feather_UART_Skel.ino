/*
  Skeleton Code for UART SERCOM on the Feather M0
*/

//TODO: clean up relay_switch function so that toggling is not necessary for each iteration
//		  of state machine.
//TODO: test fertigate functionality

//#include <Loom.h>
#include "wiring_private.h"           // pinPeripheral() function


//const char* json_config = 
//#include "config.h"
//;
//// Set enabled modules
//LoomFactory<
//  Enable::Internet::Disabled,
//  Enable::Sensors::Enabled,
//  Enable::Radios::Disabled,
//  Enable::Actuators::Disabled,
//  Enable::Max::Disabled
//> ModuleFactory{};
//
//LoomManager Loom{ &ModuleFactory };


#define UART_TX 10
#define UART_RX 11


//Tx ---> 10
//Rx ---> 11
Uart newSerial(&sercom1, UART_RX, UART_TX, SERCOM_RX_PAD_0, UART_TX_PAD_2 );

void SERCOM1_Handler() {
   newSerial.IrqHandler();
}

void setup()
{

	Serial.begin(115200);
	//while (!Serial); //Wait for the serial port to come online
	
	newSerial.begin(115200);
	
	pinPeripheral(10, PIO_SERCOM);
	pinPeripheral(11, PIO_SERCOM);
	
	while(!newSerial);
	
	delay(1000);
}


//main loop of the program, calls the state machine for individual
//tags upon successive tag responses
void loop()
{
	while(newSerial.available()) newSerial.read();
	delay(100);
}
