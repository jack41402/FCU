V=0;
A = 1000;
R = 0.04;
K = 10;
n = 1;
while abs(A.*exp(R.*K)-V)>=10^-4

    V = A.*(1+R./n).^(n.*K);
    n=n.*2;
end

display(V)
exponential_form = A.*exp(R.*K)

