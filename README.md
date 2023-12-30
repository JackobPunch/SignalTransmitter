# SignalTransmitter
## General description
This project is part of the research grant "Preparation of metrological safeguards for the introduction of systems WIM systems operating in "direct mass enforcement" (e-WIM)", from the "Polish Metrology" programme. The project manager is Ph.D. Eng Ryszard Sroka. My part in this project consists of generating previously recorded signals by a device measuring the weight of moving vehicles. The measurements were taken for different types of vehicles and stored in CSV files.
## Contents of folders
- codes - all codes sorted by the modules they are written for
- data - CSV files with data collected from the measuring device, photos of vehicles and signal runs. All sorted by individual vehicles.
## Brief description of progress
- Soldering DACs, multiplexer and I2C bus on Arduino Portenta Breakout Board
- Testing the connection, generation of rectangular and triangular signals on all DACs - [dac5](./codes/ArduinoPortenta/dac5/dac5.ino)
- Testing SD card reading - [slotSD](./codes/ArduinoPortenta/slotSD/slotSD.ino)
- Generation of a signal from a CSV file (created by cutting a part of one of the recorded signals - [signal](./data/vehicle 1/signal.csv)) on one of the DACs - [signalCSV](./codes/ArduinoPortenta/signalCSV/signalCSV.ino)
- Signals on the Arduino Portent generated slowly, comparison of the generation speed with esp32 - [slotSD](./codes/ArduinoPortenta/slotSD/slotSD.ino)
- Ordering SD card module to generate signal from CSV file on esp 32 and testing - [zadajnikpojedynczy](./codes/zadajnikpojedynczy/zadajnikpojedynczy.ino)
- Module didn't work on esp32
- Soldering of SPI bus on Arduino Portenta Breakout Board and testing SD Card module - [SD](./codes/ArduinoPortenta/SD/SD.ino)
- Module didn't work on Arduino Portenta
- Ordering anothere SD card module and testing
- Module worked
- Generation of a signal from a CSV file (same one that was mentioned previously - ) on one of the DACs - [SD](/codes/esp32/SDesp32/SDesp32.ino)
- Module worked, esp32 was generating faster than Arduino Portenta
- Switching to Arduino Uno
