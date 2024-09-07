clc;clear all

% Test the function with x = 3
x = 3;
compute_cos(x);


function cos_approx = compute_cos(x)
    cos_approx = 0;
    term = 1;
    n = 0;
    while abs(term) >= 0.0001
        
        cos_approx = cos_approx + term;
        n = n + 1;
        fprintf("%d   %.4f\n",n,cos_approx);
        term = (-1)^n * (x^(2*n)) / factorial(2*n);
    end
end