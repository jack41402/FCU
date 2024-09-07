x=3;
T=0;
n=0;
p=0;
while abs(T-cos(x))>=0.00001
    T=T+(-1)^n*(x^p)/factorial(p);
    n=n+1;
    p=p+2;
    if abs(T-cos(x))>=0.00001
    fprintf("  %d  %.4f\n", n, T)
    end
end