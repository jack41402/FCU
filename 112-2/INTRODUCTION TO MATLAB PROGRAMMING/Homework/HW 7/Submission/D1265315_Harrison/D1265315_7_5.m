k = 1;
T = 0;
i = 1;
x = 3;
while(k>=10^-6)
    T = k+T;
    k = x^i./factorial(i);
    i=i+1;
end
if(T - exp(x) <= 10^-6)
    fprintf("x = \n\t %d\n",x)
    fprintf("The result of exponential function is %.6f\n",T)
else
    fprintf("Wrong")
end
