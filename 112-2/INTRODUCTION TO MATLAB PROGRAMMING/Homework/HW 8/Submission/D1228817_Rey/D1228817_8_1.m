a=0;
for i=1:10000000
    
    a=a+((-1)^(i-1))*(1/(1+(i-1)*2));
end

a=a*4

b=0;
for i=1:4:10000000

    b=b+1/(i*(i+2));

end

b=b*8

x=1/8;
x=6*arctan(x);
y=1/57;
y=2*arctan(y);
z=1/239;
z=arctan(z);

c=4*(x+y+z)


function y=arctan(x)
    
    y=0;
    for i=1:1000000
    
    y=y+((-1)^(i-1))*((x^(1+(i-1)*2))/(1+(i-1)*2));
    end

end
