x = 3 ;
n = 0 ;
ans = 0 ;
y = @(n) (-1)^n*x^(2*n)/factorial(2*n) ;
while abs(cos(x)-ans)>1e-4
    ans = ans + y(n) ;
    disp([n+1 ans])
    n = n + 1 ;
end