x = 3;
cos_actual = cos(x); 
cos_approx = 1; 
term = 1; 
n = 1;
fprintf('%d   %.4f\n', n, cos_approx);
while abs(cos_actual - cos_approx) >= 0.0001
    term = (-1)^n * (x^(2*n) / factorial(2*n));
    cos_approx = cos_approx + term;
    fprintf('%d   %.4f\n', n+1, cos_approx);
    n = n + 1;
end

