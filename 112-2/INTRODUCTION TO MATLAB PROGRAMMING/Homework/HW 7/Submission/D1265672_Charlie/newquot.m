function newquot_a(f, x)
    for k = 0:10
        h = 10^(-k);
        y = (f(x + h) - f(x)) / h;
    end
    y = y
end
