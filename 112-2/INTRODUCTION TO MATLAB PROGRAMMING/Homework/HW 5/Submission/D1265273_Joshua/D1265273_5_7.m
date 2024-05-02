amount= [200 500 700 1000 1500];
cost=(2/100)*amount.*(amount<=500)+5;
cost=cost+ (amount > 500 & amount <= 1000).* (10 + (5/100)*(amount-500));
cost=cost+  (amount > 1000).* (35 + (10/100)*(amount-1000));
disp([amount' cost'])