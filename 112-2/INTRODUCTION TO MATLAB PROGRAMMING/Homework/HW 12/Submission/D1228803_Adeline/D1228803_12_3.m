time = [0 0.5 1 1.5 2 2.5 3 3.5 4];
voltage = [100 62 38 21 13 7 4 2 3];

X = time;
Y = log(voltage);

p = polyfit(X, Y, 1);

n = 8;
log_a = p(2); 

a = exp(log_a);

time_fit = linspace(0, 4, 100);
voltage_fit = a * exp(-n * time_fit);

figure;
hold on;
plot(time, voltage, 'o', 'MarkerSize', 6, 'MarkerEdgeColor', 'b', 'DisplayName', 'Data Points');
plot(time, voltage, '-', 'LineWidth', 0.8, 'DisplayName', 'Data Line');

ylim([0 120]);

fprintf('n = %d\n', n);