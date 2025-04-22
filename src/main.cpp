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
		Serial.println((char*)msg.buf);
	}

	if (millis() - lastmsg > 1000)
	{
		memcpy(msg.buf, "messaged", 8);
		msg.len = 8;
		msg.id = 0x1;

		can_primary.write(msg);
		Serial.println("sent");

		lastmsg = millis();
	}
}
