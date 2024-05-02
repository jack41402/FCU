y = @(x) 1 + exp(-0.2.*x).*sin(x+2);

a = fminbnd (y, 0, 10);

b = fplot (y, [0,10], 0.001);
hold on;

fprintf("(x, y) = (%2.4f, %2.4f)",a ,y(a));

y1 = @(x) 1 + exp(-0.2.*x).*sin(x + c);

c=2.5;

a1 = fminbnd (y1, 0, 10);

b1 = fplot (y1, [0,10], 0.001);

fprintf("(x, y) = (%2.4f, %2.4f)",a1 ,y1(a1));