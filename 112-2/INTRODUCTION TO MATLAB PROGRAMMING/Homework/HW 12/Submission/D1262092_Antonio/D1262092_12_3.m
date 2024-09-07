clearvars;
time = [0 0.5 1 1.5 2 2.5 3 3.5 4];
voltage = [100 62 38 21 13 7 4 2 3];

p = polyfit(time, voltage, 8);
plot(time, voltage, 'o' ,time, polyval(p, time))