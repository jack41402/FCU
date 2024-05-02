if abs(f(3)-exp(3))<10^(-6)
    fprintf('The result of exponential function is 20.085537');
end
function y = f(x)
    i=1;
    y=1;
    a=1;
    b=1;
    while (a/b) > 10^(-6)
        a = x^(i);
        b = factorial(i);
        y = y +a/b;
        i = i+1;
    end
end