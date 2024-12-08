% Provide the full or relative path to your CSV file
file_path = 'C:\Users\rolni\kody\Dziekan\SignalTransmitter\data\vehicle5\2022_12_13_13_34_55_KANAL1_KANAL2.csv';

% Read the CSV file into a table
opts = detectImportOptions(file_path, 'Delimiter', ';');
data = readtable(file_path, opts);

% Filter the table to include only rows where Loop1 and Loop2 are within the designated range
filtered_data = data(data.X > 1187 & data.X < 1600, :);

% Assuming 'X' represents the time in milliseconds
figure;
hold on;

% Plot KANAL1
plot(filtered_data.X, filtered_data.KANAL1, 'DisplayName', 'KANAL1', 'Color', 'blue');

% Plot KANAL2
plot(filtered_data.X, filtered_data.KANAL2, 'DisplayName', 'KANAL2', 'Color', 'red');

% Customize the plot
title('Data Trends Over Time');
xlabel('Time (ms)');
ylabel('Values');
legend;
grid on;

% Show the plot
hold off;