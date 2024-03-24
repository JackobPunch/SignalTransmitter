import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load the data
data = pd.read_csv('data.csv')

# Define the Gaussian function
def gaussian(x, a, b, c):
    return a * np.exp(-((x - b)**2) / (2 * c**2))

# Get the x values and y values from the data
x_values = data.index.values
y_values = data.values.flatten()

# Use curve_fit to find optimal parameters
popt, pcov = curve_fit(gaussian, x_values, y_values)

# Print the optimal parameters
print(f"Optimal parameters are a={popt[0]}, b={popt[1]}, c={popt[2]}")

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, 'b-', label='data')
plt.plot(x_values, gaussian(x_values, *popt), 'r-', label='fit: a=%5.3f, b=%5.3f, c=%5.3f' % tuple(popt))
plt.title('Plot from CSV data')
plt.xlabel('Index')
plt.ylabel('Values')
plt.legend()
plt.show()