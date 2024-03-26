#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;
int values[]={388,412,486,624,764,944,1164,1409,1573,1719,1805,1879,1906,1927,1926,1952,1956,2004,2043,2064,2088,2056,1946,1800,1603,1394,1135,925,758,642,514,445,407,404,407,401,393,384,397,379,383,373};

void setup() {
  Serial.begin(9600);

  // Try to initialize!
  if (!mcp.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  int arraySize=sizeof(values)/sizeof(values[0]);
  for(int i = 0; i < arraySize; i++) {
    mcp.setChannelValue(MCP4728_CHANNEL_A, values[i]);
    if(i >= 4) { // Stop generating signal for Channel B once Channel A is done
      mcp.setChannelValue(MCP4728_CHANNEL_B, values[i-4]);
    } 
    delayMicroseconds(150);
  }
  delay(2000);
}