import numpy as np
import matplotlib.pyplot as plt

def generate_gaussian(a, b, c):
    """
    Generates a Gaussian function with given parameters.

    Parameters:
    - a (float): The amplitude of the Gaussian.
    - b (float): The mean (center) of the Gaussian.
    - c (float): The standard deviation (width) of the Gaussian.

    Returns:
    - A function that computes the Gaussian value for a given x.
    """
    def gaussian(x):
        return a * np.exp(-((x - b)**2) / (2 * c**2))
    return gaussian

# Example usage:
# Create a Gaussian function with a=1, b=0, c=1
my_gaussian = generate_gaussian(a=1, b=0, c=0.2)

# Generate x values
x_values = np.linspace(-5, 5, 400)

# Compute y values using the Gaussian function
y_values = my_gaussian(x_values)

# Plot
plt.plot(x_values, y_values)
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Gaussian Function')
plt.grid(True)
plt.show()
