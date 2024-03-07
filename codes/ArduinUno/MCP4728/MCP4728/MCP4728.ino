#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MCP4728 Square Wave Test!");

  // Try to initialize!
  if (!mcp.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }

  // Set the output voltage for all channels to mid-range (2048)
  mcp.setChannelValue(MCP4728_CHANNEL_A, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 2048);
}

void loop() {
  // Square wave period in milliseconds
  const int period = 1000;

  // Toggle the output voltage for each channel to generate square waves
  mcp.setChannelValue(MCP4728_CHANNEL_A, 0); // Channel A low
  mcp.setChannelValue(MCP4728_CHANNEL_B, 0); // Channel B low
  mcp.setChannelValue(MCP4728_CHANNEL_C, 0); // Channel C low
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0); // Channel D low

  delay(period / 2); // Half period delay

  mcp.setChannelValue(MCP4728_CHANNEL_A, 4095); // Channel A high
  mcp.setChannelValue(MCP4728_CHANNEL_B, 4095); // Channel B high
  mcp.setChannelValue(MCP4728_CHANNEL_C, 4095); // Channel C high
  mcp.setChannelValue(MCP4728_CHANNEL_D, 4095); // Channel D high

  delay(period / 2); // Half period delay
}