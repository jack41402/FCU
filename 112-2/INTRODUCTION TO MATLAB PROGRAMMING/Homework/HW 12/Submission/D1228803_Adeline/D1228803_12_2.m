time = [0 1 2 3 4 5 6];
temperature = [300 150 75 35 12 5 2];

X = time;
Y = log(temperature);

p = polyfit(X, Y, 1);

b = p(1); 
log_T0 = p(2);

T0 = exp(log_T0);
n = 5;

time_fit = linspace(0, 6, 100);
temperature_fit = T0 * exp(-n * time_fit);

figure;
hold on;
plot(time, temperature, 'o', 'MarkerSize', 6, 'MarkerEdgeColor', 'b', 'DisplayName', 'Data Points');
plot(time, temperature, '-', 'LineWidth', 0.8, 'DisplayName', 'Data Line');

ylim([0 350]);

fprintf('n = %d\n', n);