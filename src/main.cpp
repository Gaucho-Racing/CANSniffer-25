#include <Arduino.h>
#include "FlexCAN_T4.h"
#include "send_nodes.h"
#include "Nodes.h"

#define HWRSerial Serial1

leaked_nodes test;
get_nodes result;
bool start = false;
unsigned long canFill;

#define JuanMbps 1000000

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can_primary;
FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can_data;
CAN_message_t msg;
CAN_message_t msg2;
int i = 0;
uint32_t lastmsg = 0;

void setup()
{
	pinMode (LED_BUILTIN, OUTPUT) ;
	Serial.begin(115200);
	delay(100);
	HWRSerial.begin(115200, SERIAL_8N1);
	can_primary.begin();
	can_primary.setBaudRate(1000000);
	msg.flags.extended = 1;
}

void loop()
{
	if (can_primary.read(msg))
	{
		Serial.println("recieved");
		Serial.println(msg.id, HEX);
		/*
		msg.id = 0x0001;
		can_primary.write(msg); 
		*/
	}

	if (millis() - lastmsg > 1000)
	{
		/*
		msg.id = 0x0001;
		msg.len = 8;
		msg.buf[0] = 0x00;
		msg.buf[1] = 0x00;
		msg.buf[2] = 0x00;
		msg.buf[3] = 0x00;
		msg.buf[4] = 0x00;
		msg.buf[5] = 0x00;
		msg.buf[6] = 0x00;
		msg.buf[7] = 0x69;*/
		Serial.println("sent");

		can_primary.write(msg);
		lastmsg = millis();
	}
}
