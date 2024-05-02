incomes = [5000, 10000, 15000, 22000, 30000, 38000, 50000];

tax = 0.1 * incomes.*(incomes<=10000);
tax = tax + (1000+0.2*incomes).*(10000<incomes & incomes<=20000);
tax = tax + (3000+0.3*incomes).*(20000<incomes & incomes<=40000);
tax = tax + (9000+0.5*incomes).*(40000<incomes);
disp([incomes' tax'])