time = 0:6;
temperature = [300, 150, 75, 35, 12, 5, 2];
n = 5 
p = polyfit(time, temperature, n);
fit_temperature = polyval(p, time);
figure;
plot(time, temperature, 'o');
hold on;
plot(time, fit_temperature, '-');