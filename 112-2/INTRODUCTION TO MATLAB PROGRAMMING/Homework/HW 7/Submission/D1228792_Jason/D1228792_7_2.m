y = @(x) 1 + exp(-0.2.*x) .* sin(x + 2);
x1 = 0;
x2 = 10;
a = fminbnd(y,x1,x2);
fprintf("(x, y)=\n\t%.4f\t%.4f\n",a,y(a));
y1 = @(x) 1 + exp(-0.2.*x) .* sin(x + 2.5);
b = fminbnd(y1,x1,x2);
fprintf("(x, y)=\n\t%.4f\t%.4f\n",b,y1(b));
fplot(y, [0 10]);
hold on 
fplot(y1, [0 10]);
hold off
