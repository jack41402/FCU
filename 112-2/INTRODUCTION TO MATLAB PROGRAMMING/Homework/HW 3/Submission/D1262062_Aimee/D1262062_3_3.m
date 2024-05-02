deposit = 100000;
A = deposit;
format("bank");
for i=1:12
    if A <= 110000
        interest = 0.01;
    elseif A > 110000 && A <= 125000
        interest = 0.015;
    elseif A > 125000
        interest = 0.02;
    end
    amount_of_interest = A * interest;
    A = A .* (1+interest) + 1000;
    fprintf('%d %.2f %.2f %.2f\n', i, interest, amount_of_interest, A)
end



