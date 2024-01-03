#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <SPI.h>
#include <SD.h>

#define PIN_SPI_CS 4
#define NUM_CONVERTERS 4
#define TCAADDR 0x70

Adafruit_MCP4725 p[NUM_CONVERTERS];
File myFile;
bool signalGenerated = false;

void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("SD CARD Programme");

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println(F("SD CARD FAILED, OR NOT PRESENT!"));
    while (1);
  }

  Serial.println(F("SD CARD INITIALIZED."));

  Wire.begin();

  for (uint8_t t=0; t<8; t++) {
    tcaselect(t);
    Serial.print("TCA Port #"); Serial.println(t);

    for (uint8_t addr = 0; addr<=127; addr++) {
      if (addr == TCAADDR) continue;

      Wire.beginTransmission(addr);
      if (!Wire.endTransmission()) {
        Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
      }
    }
  }
  Serial.println("done");

  Wire.begin();
  for (uint8_t i = 0; i < NUM_CONVERTERS; i++) {
    tcaselect(i);
    p[i].begin(0x62);
  }
}

void loop() {
  // Check if the signal has been generated
  if (!signalGenerated) {
    // Open the CSV file for reading
    File signalFile = SD.open("/signal2.csv", FILE_READ);

    if (signalFile) {
      Serial.println("Starting of generation");
      // Larger buffer size for reading lines with two values
      char buffer[64];

      while (signalFile.available()) {
        // Read the values from the CSV file
        signalFile.readBytesUntil('\n', buffer, sizeof(buffer));
        int value[NUM_CONVERTERS];
        sscanf(buffer, "%d;%d;%d;%d", &value[0], &value[1], &value[2], &value[3]);

        for (int i=0; i<NUM_CONVERTERS; i++) {
        /*Serial.print(i);
        Serial.print(" - ");
        Serial.println(value[i]);*/
        tcaselect(i);
        p[i].setVoltage(value[i], false);
        }
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