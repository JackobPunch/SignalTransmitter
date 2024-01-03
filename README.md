# SignalTransmitter
## General description
This project is part of the research grant "Preparation of metrological safeguards for the introduction of WIM systems operating in "direct mass enforcement" (e-WIM)", from the "Polish Metrology" programme. The project manager is Ph.D. Eng Ryszard Sroka. My part in this project is to generate previously recorded signals by a device measuring the weight of moving vehicles. The measurements were taken for different types of vehicles and stored in CSV files.
## Contents of folders
- codes - all codes sorted by the modules they are written for
- data - CSV files with data collected from the measuring device, photos of vehicles and signal runs. All sorted by individual vehicles.
## Brief description of progress
- Soldering DACs, multiplexer and I2C bus on Arduino Portenta Breakout Board
- Testing the connection, generation of rectangular and triangular signals on all DACs - [code](./codes/ArduinoPortenta/dac5/dac5.ino) [video1] [video2]
- Testing the sd card reading from the slot on the Arduino Portenta Breakout Board- [code](./codes/ArduinoPortenta/slotSD/slotSD.ino)
- Generation of a signal from a CSV file (created by cutting a part of one of the recorded signals - [signal.CSV](./data/vehicle1/signal.csv)) on one of the DACs - [code](./codes/ArduinoPortenta/signalCSV/signalCSV.ino) [photo1] [photo3]
- Signals on the Arduino Portent generated slowly, comparison of the generation of triangular signals on one DACs speed with esp32 - [code](./codes/zadajnikpojedynczy/zadajnikpojedynczy.ino) [video3]
- Ordering SD card module and testing if it works with esp32- [code](/codes/esp32/SDesp32/SDesp32.ino)
- Module didn't work with esp32
- Soldering of SPI bus on Arduino Portenta Breakout Board and testing SD Card module - [code](./codes/ArduinoPortenta/SD/SD.ino)
- Module didn't work with Arduino Portenta
- Ordering anothere SD card module and testing if it works
- Module worked
- Generation of a signal from a CSV file (same one that was mentioned previously - [signal.CSV](./data/vehicle1/signal.csv)) on one of the DACs [code](/codes/esp32/CSVsignalesp32/CSVsignalesp32.ino)
- Module worked, esp32 was generating faster than Arduino Portenta
- Switching to Arduino Uno
