function y = newquot(x)
h = 0.001;
f = @(a) a.^3 + 2.*a.^2 + 5.*a - 4;
y = (f(x + h) - f(x))./h
end
