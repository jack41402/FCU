A = 1000 ;
r = 0.04 ;
k = 10 ;
V = @(n) A*(1+r/n)^(n*k) ;
ans = 0 ;
n = 1 ;
while abs(A*exp(1)^(r*k)-V(n))>1e-4
    n = n * 2 ;
end
V = V(n)
exponential_form = A*exp(1)^(r*k)
% fprintf("The value V converges at n=%d\n" , n) ;