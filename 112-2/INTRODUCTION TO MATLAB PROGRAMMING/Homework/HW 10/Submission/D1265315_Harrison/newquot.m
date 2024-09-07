function y = newquot(x)
f = @(a) a.^3+2.*a.^2+5.*a-4
h = 10^-3;
y = (f(x+h)-f(x))/h;
end