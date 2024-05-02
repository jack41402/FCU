x=3

now=taylor(x, 2);
last=taylor(x, 1);

i=0;
while abs(now-last)>(10^-6)
    i=i+1;
    last=now;
    now=taylor(x, 2+i);

end

fprintf("The result of the exponential function is %f", now)

function e_val=taylor(x, pow)
loop=0;
    
if pow~=1
    for i=2:pow
    
     loop=loop+((x^i)/factorial(i));

    end
end
    
    e_val=loop+1+x;
end