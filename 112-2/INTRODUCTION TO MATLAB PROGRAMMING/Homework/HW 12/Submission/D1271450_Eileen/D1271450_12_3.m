time = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4];
voltage = [100, 62, 38, 21, 13, 7, 4, 2, 3];
disp("n=8");
p=polyfit(time,voltage,n);
time_fit=linspace(0,4);
voltage_fit=polyval(p,time_fit);
figure;
hold on;
plot(time, voltage, 'o', 'DisplayName', 'Data');
plot(time, fitted_voltage, '-', 'DisplayName', sprintf('Fitted curve (k = %.4f)', k_opt));
ylim([0 120]);
hold off;

