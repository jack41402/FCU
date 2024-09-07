time = [0 1 2 3 4 5 6];
t = [300 150 75 35 12 5 2];

p = polyfit(time,t,5);

plot(time,t,"o",time,polyval(p,time))

fprintf("n=5");
