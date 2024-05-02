function y = x_n(x)
    a = 2;
    n = (0:20);    
    x_n = (n .* a.^n) / factorial(n + 1);
    