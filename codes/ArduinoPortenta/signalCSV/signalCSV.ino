#include "SDMMCBlockDevice.h"
#include "FATFileSystem.h"
#include <Wire.h>
#include <Adafruit_MCP4725.h>

SDMMCBlockDevice block_device;
mbed::FATFileSystem fs("fs");
Adafruit_MCP4725 p;

// Declare a global variable for the file pointer and a smaller buffer size for reading lines
FILE *fp;
char buffer[32];

void setup() {
  delay(2000);
  Serial.begin(115200);
  Serial.println("DAC Signal from SD Card");

  int err =  fs.mount(&block_device);
  if (err) {
    Serial.println("No filesystem found, formatting... ");
    fflush(stdout);
    err = fs.reformat(&block_device);
  }

  // Open the CSV file for reading in the setup
  fp = fopen("/fs/signal.csv", "r");
  if (!fp) {
    Serial.println("Error opening file");
    // Handle the error as needed
  }

  // Initialize the DAC with its I2C address
  p.begin(0x62);
}

void loop() {
  while (fgets(buffer, sizeof(buffer), fp)) {
    // Read the value from the CSV file
    int value = atoi(buffer);

    // Set the voltage on the DAC
    p.setVoltage(value, false);

    // Wait for a short time before setting the next voltage
    //delay(10);
  }
  delay(1000);
}