# SignalTransmitter
## General description
This project is part of the research grant "Preparation of metrological safeguards for the introduction of systems WIM systems operating in "direct mass enforcement" (e-WIM)", from the "Polish Metrology" programme. The project manager is Ph.D. Eng Ryszard Sroka. My part in this project consists of generating previously recorded signals by a device measuring the weight of moving vehicles. The measurements were taken for different types of vehicles and stored in CSV files.
## Contents of folders
- codes - all codes sorted by the modules they are written for
- data - CSV files with data collected from the measuring device, photos of vehicles and signal runs. All sorted by individual vehicles.
## Brief description of progress
- The DAC converters, using a multiplexer, were connected via the I2C bus to the Arduino Portenta H7 board
- Testing the connection, generation of rectangular and triangular signals on all DACs - code [dac5](./codes/ArduinoPortenta/dac5/dac5.ino)
- Testing SD card reading - code "slotSD"
- generation of a signal from a CSV file, created by cutting a part of one of the recorded signals, on one of the DACs - code "signalCSV"
- signals on the Arduino Portent generated slowly, comparison of the generation speed with esp32 - for both modules code "zadajnik-one"
- order module on SD card to generate signal from CSV file on esp 32 and test - code "SD
