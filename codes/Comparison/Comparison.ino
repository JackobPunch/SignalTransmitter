#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 p; 

void setup() {
  delay(2000);
  Serial.begin(115200);
  Serial.println("MCP4725 Signal Generator");

  p.begin(0x62);  
}

void loop() {
  /*p.setVoltage(4095, false);
  delay(2000);
  p.setVoltage(0, false);
  delay(2000);*/
  int counter;
  for (counter = 0; counter < 4095; counter++)
  {
    p.setVoltage(counter, false);
  }
  for (counter = 4095; counter > 0; counter--)
  {
    p.setVoltage(counter, false);
  }
}