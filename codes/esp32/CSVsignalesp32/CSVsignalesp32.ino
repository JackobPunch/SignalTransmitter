#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <SPI.h>
#include <SD.h>

#define PIN_SPI_CS 5 // The ESP32 pin GPIO5 for SD Card CS

Adafruit_MCP4725 p;

File myFile;
bool signalGenerated = false;

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("SD CARD Programme");

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1); // stop the program
  }

  Serial.println(F("SD CARD INITIALIZED."));

  // Initialize the DAC with its I2C address
  p.begin(0x62);
}

void loop() {
  // Check if the signal has been generated
  if (!signalGenerated) {
    // Open the CSV file for reading
    File signalFile = SD.open("/signal.csv", FILE_READ);

    if (signalFile) {
      // Smaller buffer size for reading lines
      char buffer[32];

      while (signalFile.available()) {
        // Read the value from the CSV file
        signalFile.readBytesUntil('\n', buffer, sizeof(buffer));
        int value = atoi(buffer);

        // Set the voltage on the DAC
        p.setVoltage(value, false);

        // Wait for a short time before setting the next voltage
        delay(10);
      }

      // Close the file
      signalFile.close();

      // Set the flag to indicate that the signal has been generated
      signalGenerated = true;

      // Optionally, print a message on the serial port
      Serial.println("Signal generated. Press the reset button to generate again.");
    } else {
      Serial.println("Error opening signal.csv");
    }
  }
}