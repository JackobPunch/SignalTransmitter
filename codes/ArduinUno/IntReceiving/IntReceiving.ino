#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

void setup() {
  Serial.begin(115200);
  
  // Set pin 13 (built-in LED) as an output
  pinMode(13, OUTPUT);

  // Try to initialize!
  if (!mcp.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();  // Read integer value from serial port

    if (value >= 0 && value <= 4095) { // Ensure value is within DAC range
      mcp.setChannelValue(MCP4728_CHANNEL_A, value*500); // Set value to channel A
      // Blink the LED on pin 13
      digitalWrite(13, HIGH);
      delay(100); // Keep the LED on for 100 milliseconds
      digitalWrite(13, LOW);
      Serial.println("Value set to DAC: " + String(value*500));
    } else {
      Serial.println("Invalid value: " + String(value*500) + ". Value must be between 0 and 4095.");
    }
  }
}