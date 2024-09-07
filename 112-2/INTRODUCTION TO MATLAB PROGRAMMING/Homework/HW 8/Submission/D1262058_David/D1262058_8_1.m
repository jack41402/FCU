sum = arctan(1);
a = 4.*sum

n = 1;
sum = 0;
while(abs(sum.*8-a)>0.00005)
    term = 1./(n.*(n+2));
    n = n+4;
    sum = sum + term;
end
b = sum.*8 

c = 4.*(6.*arctan(1./8)+2.*arctan(1./57)+arctan(1./239))

function y = arctan(x)
    y = x;
    for i = 1:25000
     n = 2 * i + 1;
     term = (-1).^i.*x.^n/n;
     y = y + term;
    end
end





