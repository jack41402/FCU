time = [0 0.5 1 1.5 2 2.5 3 3.5 4];
v = [100 62 38 21 13 7 4 2 3];

p = polyfit(time,v,8);

plot(time,v,"o",time,polyval(p,time))

fprintf("n=8");