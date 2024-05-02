% Define the new tax brackets and rates
brackets = [10000, 20000, 40000, Inf];
rates = [0.1, 0.2, 0.3, 0.5];

% List of incomes
incomes = [5000, 10000, 15000, 22000, 30000, 38000, 50000];

% Calculate taxes using logical vectors
taxes = zeros(size(incomes));

% Iterate over each income
for i = 1:numel(incomes)
    income = incomes(i);
    
    % Calculate tax using logical indexing
    if income <= brackets(1)
        taxes(i) = income * rates(1);
    elseif income <= brackets(2)
        taxes(i) = 1000 + (income - brackets(1)) * rates(2);
    elseif income <= brackets(3)
        taxes(i) = 3000 + (income - brackets(2)) * rates(3);
    else
        taxes(i) = 9000 + (income - brackets(3)) * rates(4);
    end
end

% Display results
disp([incomes' taxes']);
