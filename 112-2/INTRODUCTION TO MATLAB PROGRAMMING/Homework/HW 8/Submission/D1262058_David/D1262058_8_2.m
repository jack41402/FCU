r = 0.04;
A = 1000;
k = 10;
n = 1;
v = 0;
while(abs(A.*exp(r.*k) - v)>0.0001)
    v = A.*((1+r./n).^(n.*k));
    n = n*2;
end
v
exponential_form = A.*exp(r.*k)

