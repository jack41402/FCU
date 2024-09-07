Time = 0:0.5:4;
V = [100, 63, 38, 21, 13, 7, 4, 2, 3];

disp("n=8")
p = polyfit(Time, V, 8);
Time_fit = linspace(0, 4);
V_fit = polyval(p, Time_fit);

figure;
plot(Time, V, 'o', 'MarkerSize', 8);
hold on;
plot(Time, V); 
hold off;
ylim([0 120]);
