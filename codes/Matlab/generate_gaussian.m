function gaussian = generate_gaussian(a, b, c)
    % Generates a Gaussian function with given parameters.

    % Define the Gaussian function
    gaussian = @(x) a * exp(-((x - b).^2) / (2 * c^2));
end