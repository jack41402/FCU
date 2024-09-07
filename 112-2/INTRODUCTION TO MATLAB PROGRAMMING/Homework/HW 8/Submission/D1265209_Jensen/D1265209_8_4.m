x = 3;
a = cos(x);
k=1;

while abs(mcos(x, k)-cos(x))>10^(-5)
    fprintf("%d.", k)
    disp(mcos(x, k))
    k=k+1;
end


function y = mcos(x, n)
    y = 0;
    for k = 0:n-1
        term = ((-1)^k) * (x^(2*k) / factorial(2*k));
        y = y + term;
    end
end
