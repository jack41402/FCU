time = [0, 1, 2, 3, 4, 5, 6];
temperature = [300, 150, 75, 35, 12, 5, 2];
n = 5;
p = polyfit(time, temperature, n);
time_fit = linspace(0, 6);
temperature_fit = polyval(p, time_fit);
figure;
hold on;
plot(time, temperature, 'o', 'MarkerEdgeColor', 'b', 'MarkerFaceColor', 'none');
plot(time, temperature, 'r-');
hold off;
xlim([0 6]);
ylim([0 350]);




