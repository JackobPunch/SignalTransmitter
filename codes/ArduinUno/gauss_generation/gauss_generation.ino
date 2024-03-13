#include <Adafruit_MCP4728.h>
#include <Wire.h>

// Function to generate a Gaussian
double generate_gaussian(double a, double b, double c, double x) {
    return a * exp(-pow((x - b), 2) / (2 * pow(c, 2)));
}
void setup() {
    Serial.begin(9600);

    // Example usage:
    // Parameters for the Gaussian function
    double a = 1.0;  // Amplitude
    double b = 0.0;  // Mean
    double c = 0.2;  // Standard deviation

    // Generate x values
    const int num_points = 400;
    double x_values[num_points];
    double step_size = 10.0 / (num_points - 1);
    for (int i = 0; i < num_points; ++i) {
        x_values[i] = -5.0 + i * step_size;
    }

    // Compute y values using the Gaussian function
    double y_values[num_points];
    for (int i = 0; i < num_points; ++i) {
        y_values[i] = generate_gaussian(a, b, c, x_values[i]);
    }

    // Output the x and y values
    for (int i = 0; i < num_points; ++i) {
        Serial.print("x: ");
        Serial.print(x_values[i]);
        Serial.print(", y: ");
        Serial.println(y_values[i]);
    }
}

void loop() {
    // Empty, since we only need to run the setup once.
}
