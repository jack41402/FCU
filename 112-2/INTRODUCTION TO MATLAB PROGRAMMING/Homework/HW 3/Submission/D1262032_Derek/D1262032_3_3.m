deposit = 100000;
for i= 1:12
    if deposit<=110000
        interest = 0.01;
    elseif deposit<=125000
        interest = 0.015;
    else 
        interest = 0.02;
    end
    amount_of_interest = deposit*interest;
    deposit = deposit*(1+interest);
    deposit = deposit+1000;
   fprintf("%d %1.2f %4.2f %6.2f\n" , i, interest, amount_of_interest, deposit)
end
