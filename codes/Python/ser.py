import serial
import csv
import time

# Establish serial connection (change port and baudrate according to your setup)
ser = serial.Serial('COM16', 9600, timeout=1) 

# Wait for the serial connection to initialize
time.sleep(2)

# Open the CSV file
with open('data.csv', newline='') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        for value in row:
            try:
                int_value = int(value)
                ser.write(str(int_value).encode()) # Convert int to bytes and send
                ser.write(b'\n') # Add newline character to indicate end of transmission
                time.sleep(1) # Wait for a moment before sending the next value
            except ValueError:
                print("Invalid integer value:", value)

# Close the serial connection
ser.close()