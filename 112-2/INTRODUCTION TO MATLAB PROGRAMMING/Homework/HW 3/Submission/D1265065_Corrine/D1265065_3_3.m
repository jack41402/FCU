deposit = 100000;
A = deposit;

format("bank")
for i=1:12
    if (A <= 110000)
    interest_rate = 1.01;
    elseif (A <= 125000 & A > 110000)
    interest_rate = 1.015;
    elseif (A > 125000)
    interest_rate = 1.02;
    end
    the_amount_of_interest = A .* (interest_rate-1);
    A = A .* interest_rate + 1000;
    fprintf('%d %.2f %.2f %.2f\n', i, interest_rate - 1, the_amount_of_interest, A)
end