f = @(x) x.^3 + 2.*x.^2 + 5.*x - 4;
r = -5:0.1:5;

result = newquot(f, r);
disp(result)