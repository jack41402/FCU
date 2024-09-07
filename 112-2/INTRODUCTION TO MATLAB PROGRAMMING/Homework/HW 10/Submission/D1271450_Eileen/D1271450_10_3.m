f = @(x) x.^3 + 2*x.^2 + 5*x - 4;
h = 1e-3;
x = 0;
f = @(x) x.^3 + 2*x.^2 + 5*x - 4;
x_values = -5:0.1:5;
h = 1e-3;
derivatives = zeros(size(x_values));
for i = 1:length(x_values)
    derivatives(i) = newquot_func(f, x_values(i), h);
end
disp('y=');
disp(derivatives);

function derivative = newquot_func(f, x, h)
    derivative = (f(x + h) - f(x)) / h;
end

