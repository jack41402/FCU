
function y = newquot(x)
    f = @(a) a.^3 + 2.*a.^2 + 5.*a - 4;
    y = (f(x + 0.001) - f(x))./0.001;
end