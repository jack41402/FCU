x=2004:2009;
y=10^6.*[10 10.9 11.7 12.6 13.8 14.9];
p=polyfit(x, y, 2);
a=polyval(p, x);
plot(x, y, 'o');
hold on
plot(x, a);
syms x;
s=2*y(1);
solution=solve(p(1)*(x.^2)+p(2)*x+p(3)==s, x);
t=double(solution);
t=t(t>=2009);
fprintf("t=\n     %.2f\n", t)
xticks(2004:2009);
