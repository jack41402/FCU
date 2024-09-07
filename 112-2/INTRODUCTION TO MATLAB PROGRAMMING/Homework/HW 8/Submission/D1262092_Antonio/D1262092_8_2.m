r = 0.04;
A = 1000;
k = 10;
n = 1;
V = 0;

while(abs(A.*exp(r*k) - V)>0.0001)
    V = A*((1+r/n)^(n*k));
    n = n*2;
end
V
exponential_form = A.*exp(r.*k)