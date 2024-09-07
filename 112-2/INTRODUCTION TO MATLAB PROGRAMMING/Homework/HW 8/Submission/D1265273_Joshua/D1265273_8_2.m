A = 1000;
r = 0.04;
k = 10;
v = @(n) A*(1+r/n)^(n*k);
c = A*exp(r*k);
n = 1;
while abs(v(n)-c)>1e-4
    n = n*2;
end
if (v(n)-c)<1e-6
    V = v(n)
    exponential_form = v(n)

end
