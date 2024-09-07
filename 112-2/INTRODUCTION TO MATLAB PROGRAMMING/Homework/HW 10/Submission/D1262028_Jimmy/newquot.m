function derivative = newquot(f, x)
    h = 1e-3;
    derivative = (f(x + h) - f(x)) / h;
end
