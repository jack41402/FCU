function y= newquot(x, h)
    f= @(a) a.^3;
    y= (f(x+h)-f(x))./h;
end