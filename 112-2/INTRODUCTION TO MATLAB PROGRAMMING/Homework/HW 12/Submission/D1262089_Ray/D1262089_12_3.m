time = 0:0.5:4;
voltage = [100 62 38 21 13 7 4 2 3];
n = 8
p = polyfit(time, voltage, n);
fit_voltage = polyval(p, time);
figure;
plot(time, voltage, 'o')
hold on;
plot(time, fit_voltage, '-')
