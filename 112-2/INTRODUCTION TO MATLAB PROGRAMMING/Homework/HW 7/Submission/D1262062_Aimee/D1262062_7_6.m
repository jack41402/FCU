fprintf("Standard normal function at 1 is %.6f", y(1))

function result = y(x)
    a = 0.4361836;
    b=-0.1201676;
    c = 0.937298;
    r = exp(-0.5 * x.^2) / sqrt(2 * pi);
    t = 1./(1 + 0.3326*x);
    result = 0.5 - r .* (a * t + b * t.^2 + c * t.^3);
end