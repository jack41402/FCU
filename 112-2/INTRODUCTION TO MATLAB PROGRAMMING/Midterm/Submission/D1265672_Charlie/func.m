function rats(x, n)
    b = 1;    
    for i = 1:n+1
        b = b * i;
    end
    if n*x^n / b ~= 1 && n*x^n / b ~= 0
        fprintf("%d/%d", n*x^n, b);
    else
        fprintf("%d", n*x^n/b);
    end
end