income = [5000 10000 15000 22000 30000 38000 50000];
tax = zeros(size(income));
tax(income<=10000) = income(income<=10000)*0.1;
tax(income>10000 & income<=20000) = (income(income>10000 & income<=20000)-10000)*0.2+1000;
tax(income>20000 & income<=40000) = (income(income>20000 & income<=40000)-20000)*0.3+3000;
tax(income>40000) = (income(income>40000)-40000)*0.5+9000;
total_tax = [income;tax]'
