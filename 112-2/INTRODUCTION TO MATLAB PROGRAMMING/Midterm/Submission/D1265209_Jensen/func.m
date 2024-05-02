function x = SUB_function
    s = 1;
    a = 2;
    x = 0;
    z=0;
    for n = 0:20
        s = s.*(n+1);
        z = n.*(a^n)/s;
        x = rat(z);
        fprintf('%d    %s\n', n, x)
    end
end
