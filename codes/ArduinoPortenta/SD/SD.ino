#include <SPI.h>
#include <SD.h>

File myFile;

void setup()
{
    // PIN_SPI_SS is the Chip Select pin defined in the core for the Portenta H7
    // and is defined to be the pin 7, but you can use any free pin.
    pinMode(PIN_SPI_SS, OUTPUT);
    digitalWrite(PIN_SPI_SS, HIGH);

    // Wait for Serial connection
    Serial.begin(115200);
    while (!Serial)
        ;

    SPI.begin();

    // Select the remote SPI device
    digitalWrite(PIN_SPI_SS, LOW); 

    Serial.print("Initializing SD card...");

    if (!SD.begin(PIN_SPI_SS)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop()
{
}
