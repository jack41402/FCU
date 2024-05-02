incomes = [5000, 10000, 15000, 22000, 30000, 38000, 50000];
taxes = zeros(size(incomes));
for i = 1:length(incomes)
    if incomes(i) <= 10000
        taxes(i) = 0.10 * incomes(i);
    elseif incomes(i) <= 20000
        taxes(i) = 1000 + 0.20 * (incomes(i) - 10000);
    elseif incomes(i) <= 40000
        taxes(i) = 3000 + 0.30 * (incomes(i) - 20000);
    else
        taxes(i) = 9000 + 0.50 * (incomes(i) - 40000);
    end
end

for i = 1:length(incomes)
    fprintf('%5d  %5d\n', incomes(i), taxes(i));
end
