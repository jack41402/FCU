time = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4];
voltage = [100, 62, 38, 21, 13, 7, 4, 2, 3];
p = polyfit(time, voltage, 8);
time_fit = linspace(0, 4);
voltage_fit = polyval(p, time_fit);
plot(time, voltage, 'o', 'MarkerSize', 8, 'DisplayName', 'Data'); % Original data points
hold on;
plot(time_fit, voltage_fit, '-', 'LineWidth', 0.5, 'DisplayName', 'Polynomial Fit'); % Polynomial curve
