income = [5000 10000 15000 22000 30000 38000 50000];

tax = 0.1 * income .* (income <= 10000);
tax = tax + (income > 10000 & income <= 20000) .* (0.2 * (income - 10000) + 1000);
tax = tax + (income > 20000 & income <= 40000) .* (0.3 * (income - 20000) + 3000);
tax = tax + (income > 40000) .* (0.5 * (income - 40000) + 9000);
disp([income' tax']);