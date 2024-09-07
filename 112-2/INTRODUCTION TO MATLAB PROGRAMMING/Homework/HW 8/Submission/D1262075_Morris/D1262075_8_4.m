x = 3;
a = cos(x);
n = 1;

while abs(mcos(x, n) - cos(x)) > 10^(-5)
    w = mcos(x, n);
    fprintf("%d   %.4f\n", n,w)
    n = n + 1;
end


function y = mcos(x, n)
    y = 0;
    for k = 0:n-1
        term = ((-1)^k) * (x^(2*k) / factorial(2*k));
        y = y + term;
    end
end
