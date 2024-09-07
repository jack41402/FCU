clear all;
time = [0 1 2 3 4 5 6];
temp = [300 150 75 35 12 5 2];
f = polyfit(time, temp,5);
plot(time, temp, 'o', time, polyval(f, time))
