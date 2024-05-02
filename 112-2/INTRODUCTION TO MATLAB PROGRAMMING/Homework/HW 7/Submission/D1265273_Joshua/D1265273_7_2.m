y= @(x) 1+ exp(-1*0.2*x).*sin(x+2);
a= fminbnd(y, 0, 10);
fplot(y, [0,10]);
hold on;
fprintf('(x, y)=\n %2.4f, %3.4f\n', a, y(a));
c= 2.5;
d= @(x) 1+ exp(-1*0.2*x).*sin(x+c);
b= fminbnd(d, 0, 10);
fplot(d, [0,10])
fprintf('(x, y)= \n%2.4f, %3.4f\n', b, d(b));
