close all; clear all;
time = 0 : 0.5 : 4;
volt = [100, 62, 38, 21, 13, 7, 4, 2, 3];
f = polyfit(time,volt,8);
plot(time,volt,'o',time,polyval(f,time));