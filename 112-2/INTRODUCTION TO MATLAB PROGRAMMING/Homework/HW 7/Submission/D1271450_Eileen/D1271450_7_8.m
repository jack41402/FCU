function D1271450_7_8()
function result = p(n, x)
    if n == 0
        result = 1;
    elseif n == 1
        result = x;
    else
        result = ((2*n + 1) * x * p(n - 1, x) - n * p(n - 2, x)) / (n + 1);
    end
end

x_values = input('Enter x value:');
for i = 1:numel(x_values)
    x = x_values(i);
    legendre_recursive = p(2, x);
    legendre_analytic = (3 * x^2 - 1) / 2;
    fprintf('p(2, %d) is %.6f\n', x, legendre_analytic);
end
end
