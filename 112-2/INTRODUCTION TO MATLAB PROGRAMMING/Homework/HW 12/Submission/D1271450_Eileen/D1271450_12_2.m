time = [0, 1, 2, 3, 4, 5, 6];
temperature = [300, 150, 75, 35, 12, 5, 2];
disp("n=5")
p=polyfit(time, temperature, n);
time_fit=linspace(0,6);
temperature_fit=polyval(p,time_fit);
figure;
hold on;
plot(time, temperature, 'o', 'DisplayName', 'Data');
plot(time, fitted_temperature, '-', 'DisplayName', sprintf('Fitted curve (k = %.4f)', k_opt));
ylim([0 350]);
hold off;