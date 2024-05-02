
y = @(x) 1 + exp(-0.2.*x) .* sin(x + 2);
x_min = fminbnd(y, 0, 10);
fprintf("(x, y)=\n");
disp([x_min y(x_min)]);
fplot(y,[0 10]);
hold on;
y2 = @(x, c)1 + exp(-0.2*x).*sin(x + c);
minc = fminbnd(@(x) y2(x, 2.5), 0,10);
fprintf("(x, y)=\n");
disp([minc, y2(minc, 2.5)]);
fplot(@(x) y2(x, 2.5), [0 10]);
hold off;

