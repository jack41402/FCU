function D1265154_9_3
function derivative_values = newquot(f, x_values)

h = 1e-3;
derivative_values = zeros(size(x_values));
for i = 1:length(x_values)
    derivative_values(i) = (f(x_values(i) + h) - f(x_values(i))) / h;
end
end
f = @(x) x.^3 + 2*x.^2 + 5*x - 4;
x_values = -5:0.1:5;
derivative_values = newquot(f, x_values)

end