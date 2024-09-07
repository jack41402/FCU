z = zeros(1,100);
x=3;
n=0;
while abs(sum(z)-cos(3))>=10.^(-4)
    z(n+1) =x.^(2.*n)*(-1).^n./factorial(2.*n);
    n=n+1;
end

for i=1:n
    fprintf("%d  %.4f\n",i,sum(z(1:i)));
end

