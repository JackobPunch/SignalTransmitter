#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <SPI.h>
#include <SD.h>

#define PIN_SPI_CS 5 // The ESP32 pin GPIO5 for SD Card CS
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
    while (1); // stop the program
  }

  Serial.println(F("SD CARD INITIALIZED."));

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
      // Larger buffer size for reading lines
      char buffer[256];

      // Read the header to get column names
      signalFile.readBytesUntil('\n', buffer, sizeof(buffer));

      // Split the header into column names
      String header(buffer);
      int columnCount = 0;

      // Count the number of semicolons to determine the number of columns
      for (int i = 0; i < header.length(); i++) {
        if (header.charAt(i) == ';') {
         columnCount++;
        }
      }

      // Array to store column names
      String columns[columnCount + 1]; // Adding 1 to include the last column

      // Parse column names
      int colIndex = 0;
      int startIndex = 0;
      for (int i = 0; i < header.length(); i++) {
        if (header.charAt(i) == ';') {
          columns[colIndex++] = header.substring(startIndex, i);
          startIndex = i + 1;
        }
      }
      columns[colIndex] = header.substring(startIndex);

      // Read data and generate signals
      while (signalFile.available()) {
        signalFile.readBytesUntil('\n', buffer, sizeof(buffer));

        // Split the row into values
        String row(buffer);
        int values[columnCount];

        colIndex = 0;
        startIndex = 0;
        for (int i = 0; i < row.length(); i++) {
          if (row.charAt(i) == ',') {
            values[colIndex++] = row.substring(startIndex, i).toInt();
            startIndex = i + 1;
          }
        }
        values[colIndex] = row.substring(startIndex).toInt();

        // Set the voltage on each DAC using a different column
        for (int i = 0; i < NUM_CONVERTERS; i++) {
          tcaselect(i);
          p[i].setVoltage(values[i], false);
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