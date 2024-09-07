A=1000;
r=0.04;
k=10;
for n=1:2:199999
    if(abs(A*exp(r*k)-f(n))<=1e-4)
        break;
    end
end
V=f(n)
exponential_form=A*exp(r*k)
function y=f(x)
    A=1000;
    r=0.04;
    k=10;
    y=A*(1+r/x)^(x*k);
end