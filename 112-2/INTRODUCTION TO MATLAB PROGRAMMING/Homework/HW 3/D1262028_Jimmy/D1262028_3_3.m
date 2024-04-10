sum = 100000;
for month = 1:12
    if sum <= 110000
        rate = 0.01;
        interest = sum * rate;
        sum = sum + interest + 1000;
        fprintf("%d %1.2f %1.2f %1.2f\n", month, rate, interest, sum);
    elseif 110000 < sum && sum <= 125000
        rate = 0.015;
        interest = sum * rate;
        sum = sum + interest + 1000;
        fprintf("%d %1.2f %1.2f %1.2f\n", month, rate, interest, sum);
    else
        rate = 0.02;
        interest = sum * rate;
        sum = sum + interest + 1000;
        fprintf("%d %1.2f %1.2f %1.2f\n", month, rate, interest, sum);
    end
end 