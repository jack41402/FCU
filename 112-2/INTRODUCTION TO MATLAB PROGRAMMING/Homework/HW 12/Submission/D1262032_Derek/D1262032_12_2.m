x=0:6;
y=[300 150 75 35 12 5 2];
n=5
p=polyfit(x, y, n);
p1=polyval(p, x);
plot(x, y, 'o');
hold on;
plot(x, p1);
