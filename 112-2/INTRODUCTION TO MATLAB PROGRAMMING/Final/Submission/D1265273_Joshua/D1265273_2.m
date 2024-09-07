clear all;
time = [0 1 2 3 4 5];
temp = [20 25 27 28 27 25];
f = polyfit(time, temp, 4);
y = polyval(f, 3.6)
