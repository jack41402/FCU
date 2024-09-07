time = [0, 1, 2, 3, 4, 5, 6];
temperature = [300, 150, 75, 35, 12, 5, 2];
p = polyfit(time, temperature, 5);
time_fit = linspace(0, 6);
temperature_fit = polyval(p, time_fit);
plot(time, temperature, 'o', 'MarkerSize', 8, 'DisplayName', 'Data'); % Original data points
hold on;
plot(time_fit, temperature_fit, '-', 'LineWidth', 0.5, 'DisplayName', 'Polynomial Fit'); % Polynomial curve
