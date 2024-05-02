deposit = 100000;

for i=1:12
if deposit <= 110000
    rate = 0.01;
    interest = rate*deposit;
    deposit = deposit*(1+rate)+1000;
    
elseif deposit<=125000
    rate = 0.015;
    interest = rate*deposit;
    deposit = deposit*(1+rate)+1000;

else 
    rate = 0.02;
    interest = rate*deposit;
    deposit = deposit*(1+rate)+1000;
  
end
 
    fprintf("%d %.2f %4.2f %6.2f\n", i, rate, interest, deposit);
end