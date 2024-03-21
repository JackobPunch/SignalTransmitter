#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

int charToInt(char c) {
    return c - '0';
}

int stringToInt(char* str) {
    int result = 0;
    int i = 0;
    while (str[i] != '\0') {
        result = result * 10 + charToInt(str[i]);
        i++;
    }
    return result;
}

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
    if (Serial.available() > 0) { // Check if there's data available to read
    char receivedChar = Serial.read(); // Read the incoming byte
    int value = stringToInt(&receivedChar);

    if (value >= 0 && value <= 4095) { // Ensure value is within DAC range
      mcp.setChannelValue(MCP4728_CHANNEL_A, value); // Set value to channel A
      // Blink the LED on pin 13
      digitalWrite(13, HIGH);
      delay(100); // Keep the LED on for 100 milliseconds
      digitalWrite(13, LOW);
      Serial.println("Value set to DAC: " + String(value));
    } else {
      Serial.println("Invalid value: " + String(value) + ". Value must be between 0 and 4095.");
    }
  }
}
}