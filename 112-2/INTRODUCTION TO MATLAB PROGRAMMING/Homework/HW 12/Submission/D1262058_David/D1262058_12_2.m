clear all;
times = 0:6;
temp = [300 150 75 35 12 5 2];
polyfit(times, temp, 5);
plot(times, temp, 'o', times, temp);