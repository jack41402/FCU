function y = newquot(x)
    h = 10^-3;
    f = @(x) x.^3 + 2.*x.^2 + 5.*x - 4;
    y = (f(x+h)-f(x))/h;
end