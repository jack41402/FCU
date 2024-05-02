x=3
e(x);
exp(x);
if e(x)-exp(x)<=10.^(-6)
    fprintf("The result of exponential function is %f",e(x))
end
function y=e(x)
temp=1;
y=0;
i=1;
while temp>=10.^(-6)
y=y+temp;
temp=x.^(i)./factorial(i);
i=i+1;
end
end
