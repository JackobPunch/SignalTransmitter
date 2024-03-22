% Example usage:
% Create a Gaussian function with a=1, b=0, c=0.2
my_gaussian = generate_gaussian(1, 0, 0.2);

% Generate x values
x_values = linspace(-5, 5, 400);

% Compute y values using the Gaussian function
y_values = my_gaussian(x_values);

% Plot
plot(x_values, y_values);
xlabel('x');
ylabel('f(x)');
title('Gaussian Function');
grid on;