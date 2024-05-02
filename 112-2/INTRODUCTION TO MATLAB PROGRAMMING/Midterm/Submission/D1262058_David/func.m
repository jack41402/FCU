function y = func(a, n)
    d = 1;
    m = n+1;
    for i = 1:m;
       d = d*m;
       m = m-1;
    end
    y = n*a^n/d;
end