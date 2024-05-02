salary_levels = [12000, 15000, 18000, 24000, 35000, 50000, 70000];
num_employees = [3000, 2500, 1500, 1000, 400, 100, 25];

taxes = zeros(size(salary_levels));
for i = 1:length(salary_levels)
    if salary_levels(i) <= 10000
        taxes(i) = 0.10 * salary_levels(i);
    elseif salary_levels(i) <= 20000
        taxes(i) = 1000 + 0.20 * (salary_levels(i) - 10000);
    elseif salary_levels(i) <= 40000
        taxes(i) = 3000 + 0.30 * (salary_levels(i) - 20000);
    else
        taxes(i) = 9000 + 0.50 * (salary_levels(i) - 40000);
    end
end

total_taxes = taxes .* num_employees;

average_salary = mean(salary_levels);

employees_above = sum(num_employees(salary_levels > average_salary));
employees_below = sum(num_employees(salary_levels < average_salary));

total_salary = sum(salary_levels .* num_employees);
total_employees = sum(num_employees);
average_salary_per_individual = total_salary / total_employees;

fprintf('\n(a) The average salary level is: $%d\n', average_salary);
fprintf('(b) Number of employees above average salary: %d\n', employees_above);
fprintf('    Number of employees below average salary: %d\n', employees_below);
fprintf('(c) The average salary per individual is: $%.2f\n', average_salary_per_individual);
