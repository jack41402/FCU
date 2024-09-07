x = 3;
cosx = cos(x);
cos_x = 1;
n = 2;
tolerance = 0.0001; % Define the tolerance
fprintf("1\t%.4f\n", cos_x);
while abs(cos_x - cosx) >= tolerance
    term = (-1)^(n-1) * (x^(2*n - 2)) / factorial(2*n - 2); % Compute the next term
    cos_x = cos_x + term;
    fprintf("%d\t%.4f\n", n, cos_x);
    n = n + 1;
end
