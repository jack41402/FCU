incomes = [5000, 10000, 15000, 22000, 30000, 38000, 50000];
tax_payable = zeros(size(incomes));

for i = 1:length(incomes)
    if incomes(i) <= 10000
        tax_payable(i) = 0.10 * incomes(i);
    elseif incomes(i) <= 20000
        tax_payable(i) = 1000 + 0.20 * (incomes(i) - 10000);
    elseif incomes(i) <= 40000
        tax_payable(i) = 3000 + 0.30 * (incomes(i) - 20000);
    else
        tax_payable(i) = 9000 + 0.50 * (incomes(i) - 40000);
    end
end


disp('Income        Tax Payable');
disp([incomes', tax_payable']);





