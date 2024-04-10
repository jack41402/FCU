
initial_amount = 100000;
monthly_deposit = 1000;
months = 12;
interest_rates = [0.01, 0.015, 0.02];
interest_thresholds = [110000, 125000];


balance = initial_amount;
total_interest = 0;

for month = 1:months
   
    if balance <= interest_thresholds(1)
        interest_rate = interest_rates(1);
    elseif balance <= interest_thresholds(2)
        interest_rate = interest_rates(2);
    else
        interest_rate = interest_rates(3);
    end
    
  
    monthly_interest = balance * interest_rate;
    total_interest = total_interest + monthly_interest;
    
   
    balance = balance + monthly_deposit + monthly_interest;
    
   
    fprintf('%d\t%.2f\t%.2f\t%.2f\n', month, interest_rate, monthly_interest, balance);
end



