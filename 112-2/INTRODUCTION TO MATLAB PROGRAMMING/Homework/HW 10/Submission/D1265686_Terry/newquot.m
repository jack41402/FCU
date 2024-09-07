
function y = a(f,x)
    h = 10.^(-3);
    y = (f(x+h)-f(x))./h;
end