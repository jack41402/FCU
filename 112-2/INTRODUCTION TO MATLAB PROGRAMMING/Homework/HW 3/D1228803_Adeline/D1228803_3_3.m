save = 100000;
deposit = 1000;

for i = 1:12
    if save < 110000
        rate = 0.01;
    elseif save < 125000
        rate = 0.015;
    else 
        rate = 0.02;
    end
    amount = save * rate;
    balance = save + amount;
    if rate == 0.015
        fprintf('%d %.3f %.2f %.2f\n', i, rate, amount, balance + 1000)
    else
        fprintf('%d %.2f %.2f %.2f\n', i, rate, amount, balance + 1000)
    end
    save = balance + deposit;
end
