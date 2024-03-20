#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

// Parameters for the Gaussian function
double a = 1.0;  // Amplitude
double b = 0.0;  // Mean
double c = 0.2;  // Standard deviation
const int num_points = 400;
double x_values[num_points];
int count = 0; // Counter for non-zero values

// Array to store non-zero f values
int non_zero_f_values[num_points];
const int deleyValue = 5; // Changed to const int
int f_values_with_zeroes[num_points + deleyValue];

// Function to generate a Gaussian
double generate_gaussian(double a, double b, double c, double x) {
    return a * exp(-pow((x - b), 2) / (2 * pow(c, 2)));
}

void setup() {
    Serial.begin(9600);

    // Try to initialize!
    if (!mcp.begin()) {
        Serial.println("Failed to find MCP4728 chip");
        while (1) {
            delay(10);
        }
    }
    // Generate x values
    double step_size = 10.0 / (num_points - 1);
    for (int i = 0; i < num_points; ++i) {
        x_values[i] = -5.0 + i * step_size;
    }

    // Initialize first deleyValue values with zeroes
    for (int i = 0; i < deleyValue; ++i) {
        f_values_with_zeroes[i] = 0;
    }

    // Compute y values using the Gaussian function
    for (int i = 0; i < num_points; ++i) {
        double y_value = generate_gaussian(a, b, c, x_values[i]);
        int f = static_cast<int>(y_value * 3500.0);
        Serial.println(i);
        if (f != 0) {
            non_zero_f_values[count] = f;
            f_values_with_zeroes[count + deleyValue] = f;
            count++;
        }
    }

    // Output non-zero f values
    Serial.println("Non-zero f values:");
    for (int i = 0; i < count; ++i) {
        Serial.println(non_zero_f_values[i]);
    }
}

void loop() {
    for (int i = 0; i < count; ++i) {
        mcp.setChannelValue(MCP4728_CHANNEL_A, non_zero_f_values[i]);
        mcp.setChannelValue(MCP4728_CHANNEL_B, f_values_with_zeroes[i]);
    }
    delay(2000);
}