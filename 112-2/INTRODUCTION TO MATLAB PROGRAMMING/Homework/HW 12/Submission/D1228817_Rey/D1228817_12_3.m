clear;

t=0:0.5:4;
V=[100 62 38 21 13 7 4 2 3];
n=8;
fprintf("n=%d\n", n);

p=polyfit(t, V, n);

plot(t, V, 'o', t, polyval(p, t), '-');