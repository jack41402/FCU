function x = func(a, n)
    for n = 1:1:n+1
        n_1 = 1;
        n_2 = n_1*n;
        n_1 = n_2;
    end
    x = (n.*(a^n))./n_2;
end