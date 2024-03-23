import csv

def create_new_csv_without_every_second_row(input_csv, output_csv):
    # Read the original CSV file
    with open(input_csv, 'r', newline='') as file:
        reader = csv.reader(file)
        data = [row for row in reader]

    # Remove every second row
    new_data = [row for i, row in enumerate(data) if (i + 1) % 2 != 0]

    # Write the modified data to a new CSV file
    with open(output_csv, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(new_data)

# Example usage: Create a new CSV file without every second row from 'example.csv'
input_csv_path = r'C:\Users\rolni\OneDrive\Pulpit\Kody\Dziekan\SignalTransmitter\data\vehicle1\signal2.csv'
output_csv_path = r'C:\Users\rolni\OneDrive\Pulpit\Kody\Dziekan\SignalTransmitter\data\vehicle1\new_signal2.csv'
create_new_csv_without_every_second_row(input_csv_path, output_csv_path)