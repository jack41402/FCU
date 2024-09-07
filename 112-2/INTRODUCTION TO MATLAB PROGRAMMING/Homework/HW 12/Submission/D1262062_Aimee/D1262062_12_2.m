Time = 0:6;
Temp = [300, 150, 75, 35, 12, 5, 2];

disp("n=5")
p = polyfit(Time, Temp, 5);
Time_fit = linspace(0, 6);
Temp_fit = polyval(p, Time_fit);

figure;
plot(Time, Temp, 'o', 'MarkerSize', 8);
hold on;
plot(Time, Temp); 
hold off;
ylim([0 350]);
