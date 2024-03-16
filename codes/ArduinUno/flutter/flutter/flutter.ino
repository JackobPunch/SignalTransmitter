const int ledPin = 13; // Define the pin connected to the LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(115200);    // Initialize serial communication at 115200 baud rate
  digitalWrite(ledPin, LOW); // Turn off the LED
}

void loop() {
  if (Serial.available() > 0) { // Check if there's data available to read
    char receivedChar = Serial.read(); // Read the incoming byte
    if (receivedChar == '1') { // If the received byte is '1'
      digitalWrite(ledPin, HIGH); // Turn on the LED
    } else if (receivedChar == '0') { // If the received byte is '0'
      digitalWrite(ledPin, LOW); // Turn off the LED
    }
  }
  delay(1000);
  digitalWrite(ledPin, LOW); // Turn off the LED
}