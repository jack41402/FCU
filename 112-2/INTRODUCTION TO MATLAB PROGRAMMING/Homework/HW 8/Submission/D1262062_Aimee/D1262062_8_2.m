A = 1000; 
r = 0.04;
k = 10;

for i = 0:11
    n = 2^i;
    V = A * (1 + r/n)^(n*k);
end
format shortE;
V
V_exp = A * exp(r * k);
exponential_form = V_exp