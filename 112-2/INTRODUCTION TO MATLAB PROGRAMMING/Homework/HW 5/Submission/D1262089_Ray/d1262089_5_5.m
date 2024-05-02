% Salary levels (dollars) and corresponding number of employees
salary_levels = [12000, 15000, 18000, 24000, 35000, 50000, 70000];
num_employees = [3000, 2500, 1500, 1000, 400, 100, 25];

% Taxable income for each salary level
taxable_income = salary_levels - 10000;

% Tax payable for each salary level
tax_payable = zeros(size(salary_levels));
tax_payable(taxable_income <= 0) = 0.1 * salary_levels(taxable_income <= 0);
tax_payable(taxable_income > 0 & taxable_income <= 10000) = 1000 + 0.2 * taxable_income(taxable_income > 0 & taxable_income <= 10000);
tax_payable(taxable_income > 10000 & taxable_income <= 20000) = 3000 + 0.3 * (taxable_income(taxable_income > 10000 & taxable_income <= 20000) - 20000);
tax_payable(taxable_income > 20000 & taxable_income <= 40000) = 9000 + 0.5 * (taxable_income(taxable_income > 20000 & taxable_income <= 40000) - 40000);

% (a) Average salary level
average_salary = mean(salary_levels);
disp(['Average salary level: ', num2str(average_salary)]);

% (b) Number of employees above and below the average salary level
logic_vector = salary_levels >average_salary ;
above = logic_vector.*num_employees;
sum(above);
logic_vector = salary_levels < average_salary;
below = logic_vector.*num_employees;
fprintf("%d above, %d below\n", sum(above), sum(below))


% (c) Average salary earned by an individual in the company
total_salary_bill = sum(salary_levels .* num_employees);
total_employees = sum(num_employees);
average_salary_individual = total_salary_bill / total_employees;

disp(['Average salary earned by an individual: ', num2str(average_salary_individual)]);