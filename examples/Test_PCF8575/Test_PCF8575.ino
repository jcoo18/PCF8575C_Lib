#include "jcoo18/PCF8575C_Lib/src/PCF8575C.h"
#include <Wire.h>

PCF8575C device;

void setup()
{
    Serial.begin(115200);

    Wire.begin();

    // Start device at address and chect return communication.
    uint8_t response = device.begin(0x27);

    Serial.print("Response: ");
    Serial.println(response);

}

void loop()
{
    device.digitalWrite(0x00FF);
    response = device.getPorts();
    Serial.print("Response: ");
    Serial.println(response);
    delay(1000);

    device.digitalWrite(0xFF00);
    response = device.getPorts();
    Serial.print("Response: ");
    Serial.println(response);
    delay(1000);


}