import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def gaussian(x, a, b, c):
    return a * np.exp(-((x - b)**2) / (2 * c**2))

file_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle1\2022_12_13_13_59_34_KANAL1_KANAL2.csv'

# Read the CSV file into a DataFrame
df = pd.read_csv(file_path, delimiter=';')

# Filter the DataFrame to include only rows where Loop1 and Loop2 are within the designated range
df = df[(df['X'] > 609) & (df['X'] < 2275)]

# Define the regions manually
regions = [(100, 200), (300, 400), (500, 600)]  # replace with your actual regions

# For each region, fit a Gaussian
for start, end in regions:
    # Define a region
    region = df.iloc[start:end]
    
    # Get the x values and y values from the region
    x_values = region['X'].values
    y_values = region['KANAL1'].values

    # Use curve_fit to find optimal parameters
    popt, pcov = curve_fit(gaussian, x_values, y_values)

    # Print the optimal parameters
    print(f"Optimal parameters for region {start}-{end} are a={popt[0]}, b={popt[1]}, c={popt[2]}")

    # Plot the data
    plt.figure(figsize=(10, 6))
    plt.plot(x_values, y_values, 'b-', label='data')
    plt.plot(x_values, gaussian(x_values, *popt), 'r-', label='fit: a=%5.3f, b=%5.3f, c=%5.3f' % tuple(popt))
    plt.title('Plot from CSV data')
    plt.xlabel('Index')
    plt.ylabel('Values')
    plt.legend()
    plt.show()