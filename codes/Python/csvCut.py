import pandas as pd
import csv

def create_new_csv_without_every_second_and_third_row(input_csv, output_csv):
    # Read the original CSV file
    with open(input_csv, 'r', newline='') as file:
        reader = csv.reader(file)
        data = [row for row in reader]

    # Remove every second and third row
    new_data = [row for i, row in enumerate(data) if (i + 1) % 6 == 0]

    # Write the modified data to a new CSV file
    with open(output_csv, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(new_data)

file_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle1\2022_12_13_13_59_34_KANAL1_KANAL2.csv'

# Read the CSV file into a DataFrame
df = pd.read_csv(file_path, delimiter=';')

# Filter the DataFrame to include only rows where Loop1 and Loop2 are within the designated range
df = df[(df['X'] > 609) & (df['X'] < 2275)]

df = df['KANAL1']

# Write the filtered DataFrame to a temporary CSV file
temp_csv_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle1\temp.csv'
df.to_csv(temp_csv_path, index=False)

# Apply the function to the temporary CSV file
output_csv_path = r'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle1\new_file.csv'
create_new_csv_without_every_second_and_third_row(temp_csv_path, output_csv_path)