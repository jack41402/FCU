clear all;
time = [0 0.5 1 1.5 2 2.5 3 3.5 4];
vol = [100 62 38 21 13 7 4 2 3];
f = polyfit(time, vol, 8);
plot(time, vol,'o',time,polyval(f, time) )