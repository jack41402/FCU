
x = -5:0.1:5;
f = @(x) x.^3 + 2.*x.^2 + 5.*x - 4;
y = newquot(f,x)