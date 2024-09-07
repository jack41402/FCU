time=[0 1 2 3 4 5 6];
temperature=[300 150 75 35 12 5 2];

n=5;

fprintf("n=%d\n", n);

p=polyfit(time, temperature, n);

plot(time, temperature, 'o', time, polyval(p, time), '-');