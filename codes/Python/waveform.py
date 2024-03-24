import pandas as pd
import matplotlib.pyplot as plt

# Provide the full or relative path to your CSV file
file_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle1\2022_12_13_13_59_34_KANAL1_KANAL2.csv'

# Read the CSV file into a DataFrame
df = pd.read_csv(file_path, delimiter=';')

# Filter the DataFrame to include only rows where Loop1 and Loop2 are within the designated range
df = df[(df['X'] > 609) & (df['X'] < 2275)]

# Assuming 'X' represents the time in milliseconds
plt.figure(figsize=(12, 6))

# Plot KANAL1
plt.plot(df['X'], df['KANAL1'], label='KANAL1', color='blue')

# Plot KANAL2
plt.plot(df['X'], df['KANAL2'], label='KANAL2', color='red')

# Plot Loop1
plt.plot(df['X'], df['Loop1'], label='x_Loop1', color='green')

# Plot Loop2
plt.plot(df['X'], df['Loop2'], label='x_Loop2', color='purple')

# Customize the plot
plt.title('Data Trends Over Time')
plt.xlabel('Time (ms)')
plt.ylabel('Values')
plt.legend()

# Show the plot
plt.grid(True)
plt.show()