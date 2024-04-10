sum= 100000;
for i=1:12
    if sum<=110000
        rate= 0.01;
        interest= sum.*0.01;
        sum= sum+interest+1000;
        fprintf('%d %1.2f %1.2f %1.2f\n', i, rate, interest, sum);
    elseif 110000<sum && sum<=125000
        rate= 0.015;
        interest= sum.*0.015;
        sum= sum+ interest+1000;
        fprintf('%d %1.2f %1.2f %1.2f\n', i, rate, interest, sum);
    else
        rate= 0.02;
        interest= sum.*0.02;
        sum= sum+interest+1000;
        fprintf('%d %1.2f %1.2f %1.2f\n', i, rate, interest, sum);
    end
end
    