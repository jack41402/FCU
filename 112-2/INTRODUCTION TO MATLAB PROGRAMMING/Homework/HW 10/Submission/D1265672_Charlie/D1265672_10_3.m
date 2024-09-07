x = -5:0.1:5;
f = @(x) x.^3 + 2.*x.^2 + 5.*x - 4;
y = a(f,x)

function y = a(f,x)
    h = 10.^(-3);
    y = (f(x+h)-f(x))./h;
end