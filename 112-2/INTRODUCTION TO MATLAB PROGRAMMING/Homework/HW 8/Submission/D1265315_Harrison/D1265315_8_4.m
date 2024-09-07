sum = 0;
x=3;
i=0;
while(abs(sum - cos(3))>0.0001)
    term = (-1).^i.*x.^(2.*i)./factorial(2.*i);
    i = i + 1;
    sum = sum + term;
    fprintf("%d   %.4f\n", i, sum);
end
