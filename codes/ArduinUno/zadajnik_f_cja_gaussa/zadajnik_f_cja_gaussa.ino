// Basic demo for configuring the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

int gaussianValuesIntCh1[120] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 3, 8, 14, 21, 29, 39, 51, 65, 81, 101, 123, 150, 180, 215, 254, 299, 350, 408, 471, 543, 621, 707, 801, 904, 1014, 1133, 1259, 1393, 1533, 1680, 1833, 1990, 2151, 2314, 2478, 2642, 2803, 2961, 3113, 3258, 3395, 3521, 3635, 3735, 3821, 3892, 3945, 3981, 4000, 4000, 3981, 3945, 3892, 3821, 3735, 3635, 3521, 3395, 3258, 3113, 2961, 2803, 2642, 2478, 2314, 2151, 1990, 1833, 1680, 1533, 1393, 1259, 1133, 1014, 904, 801, 707, 621, 543, 471, 408, 350, 299, 254, 215, 180, 150, 123, 101, 81, 65, 51, 39, 29, 21, 14, 8, 3, 0};
int gaussianValuesIntCh2[120] = {0,0,0,0,0,0,0,0,0,0,0, 3, 8, 14, 21, 29, 39, 51, 65, 81, 101, 123, 150, 180, 215, 254, 299, 350, 408, 471, 543, 621, 707, 801, 904, 1014, 1133, 1259, 1393, 1533, 1680, 1833, 1990, 2151, 2314, 2478, 2642, 2803, 2961, 3113, 3258, 3395, 3521, 3635, 3735, 3821, 3892, 3945, 3981, 4000, 4000, 3981, 3945, 3892, 3821, 3735, 3635, 3521, 3395, 3258, 3113, 2961, 2803, 2642, 2478, 2314, 2151, 1990, 1833, 1680, 1533, 1393, 1259, 1133, 1014, 904, 801, 707, 621, 543, 471, 408, 350, 299, 254, 215, 180, 150, 123, 101, 81, 65, 51, 39, 29, 21, 14, 8, 3, 0,0,0,0,0,0,0,0,0,0,0};


void setup() {
  Serial.begin(115200);
  // while (!Serial) {
  //   delay(100);
  // }

  // Serial.println("Adafruit MCP4728 Initial test!");

  // Try to initialize!
  if (!mcp.begin()) {
    // Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(1000);
      // Serial.println("Failed to find MCP4728 chip");
    }
  }

  mcp.setChannelValue(MCP4728_CHANNEL_A, 200);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 500);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 1000);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 1500);
}

void loop() {
   delay(1000); 
  //  Serial.println("Main Loop Increment");
   generateGaussianValueForChannel(MCP4728_CHANNEL_A);
}

void generateGaussianValueForChannel(MCP4728_channel_t channel_ID) {
  for (int i = 0; i < 120; i++) {
    mcp.setChannelValue(MCP4728_CHANNEL_A, gaussianValuesIntCh1[i]);
    mcp.setChannelValue(MCP4728_CHANNEL_B, gaussianValuesIntCh2[i]);
    Serial.println("Channel A generated value");
    delay(1);
  }
}
