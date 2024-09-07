x=0:0.5:4;
y=[100 62 38 21 13 7 4 2 3];
n=8
p=polyfit(x, y, n);
p1=polyval(p, x);
plot(x, y, 'o');
hold on;
plot(x, p1);
