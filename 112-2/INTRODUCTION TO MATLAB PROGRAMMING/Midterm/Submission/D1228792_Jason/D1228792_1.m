k = -pi/2 : pi/20 : pi/2;
t = 0 : 0.2 : 4;
A = 5;
B = 2;
a = (exp(-0.2 .* t) .* sin(B .* k) + reallog(t + 1)) .* (cos(2 * k)) .^ 2
b = ((sin(A .* t)) .^ -1 + reallog(t .^ 2 + 2 * t + 1)) .* tan(k/2)
c = (exp(t) + sin(k)) ./ B