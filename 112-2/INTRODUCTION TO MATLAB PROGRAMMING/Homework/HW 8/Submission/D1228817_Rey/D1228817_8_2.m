A=1000;
r=0.04;
k=10;
V=0;
i=1;

while abs(A*exp(r*k)-V)>=10^-4
    
    n=2^(i-1);

    V=A*(1+r/n)^(n*k);
    i=i+1;

end

display(V);

exponential_form =A*exp(r*k)

    



