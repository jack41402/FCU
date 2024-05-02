x = 3
if abs(exp(x)-f(x)) < 10^(-6)
    fprintf("The result of exponential function is %.6f\n", f(x))
end
function y = f(x)
i=0;
e=x.^i/factorial(i);
while e >= 10^(-6)
    e = x.^i/factorial(i);
    i=i+1;
end
y=0;
for j=0:1:i-2
    y = y+x.^j/factorial(j);
end
end
