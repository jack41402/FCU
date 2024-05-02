x=0:0.001:10;

y = @(x) 1+exp(-0.2*x)*sin(x+2);

MIN=fminbnd(y, 0, 10);
fprintf("(%.4f, %.4f)", MIN, y(MIN))

fplot(y, [0,10], 0.001)
hold on;

y = @(x) 1+exp(-0.2*x)*sin(x+2.5);
MIN=fminbnd(y, 0, 10);
fprintf("(%.4f, %.4f)", MIN, y(MIN))
fplot(y, [0,10], 0.001)

