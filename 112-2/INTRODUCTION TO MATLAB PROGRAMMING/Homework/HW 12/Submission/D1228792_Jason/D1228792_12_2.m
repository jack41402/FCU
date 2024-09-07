close all; clear all;
time = 0 : 1 : 6;
temperature = [300, 150, 75, 35, 12, 5, 2];
f = polyfit(time,temperature,5);
plot(time,temperature,'o',time,polyval(f,time));