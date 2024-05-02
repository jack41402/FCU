k = 1;
Tay = 0;
i = 1;
x = 3;
while(k>=10^-6)
    Tay = Tay + k;
    k = x ^ i ./ factorial(i);
    i = i + 1;
end
if(Tay - exp(x) <= 10^-6)
    fprintf("x =\n\t %d\n",x)
    fprintf("The result of exponential function is %.6f\n",Tay)
else
    fprintf("Wrong")
end