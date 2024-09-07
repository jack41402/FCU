a=0;
b=0;
n=0;
for i=1:2:199999
    a=a+((-1)^(n))*(1/i);
    n=n+1;
end
a=4*a

for i=1:4:49999
    b=b+1/(i*(i+2));
end
b=b*8

c=4*(6*f(1/8)+2*f(1/57)+f(1/239))
function y=f(x)
    p=0;
    y=0;
    for i=1:2:99
        y=y+((-1)^(p))*((x^i)/i);
        p=p+1;
    end
end
