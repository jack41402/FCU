deposit = 100000;
for i=1:12
    month = i;
    if (deposit<=110000)
        rate = 0.01;
    elseif(deposit>110000 && deposit<=125000)
        rate = 0.015;
    elseif(deposit>125000)
        rate = 0.02;
    end
    interst = deposit.*rate;
    deposit = deposit + interst + 1000;
    fprintf("%d %.2f %.2f %.2f\n", i, rate, interst, deposit)
end
