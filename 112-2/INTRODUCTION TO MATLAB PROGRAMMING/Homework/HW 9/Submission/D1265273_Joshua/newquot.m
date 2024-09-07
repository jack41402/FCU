function y= newquot(x)
    f= @(a) a.^3+2.*(a.^2)+5.*a-4;
    y= (f(x+10^(-3))-f(x))./10^(-3);
end