x = -5:0.1:5;
h = 1e-3;
f = @(x) x.^3 + 2*x.^2 + 5*x - 4; 

derivative = (f(x + h) - f(x)) / h;

x_values = -5:0.1:5;
f = @(x) x.^3 + 2*x.^2 + 5*x - 4;
y = newquot(f, x_values);
disp(y);