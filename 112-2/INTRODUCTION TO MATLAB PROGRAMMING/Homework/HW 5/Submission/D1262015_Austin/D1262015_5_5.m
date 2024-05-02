%5.5
salary_levels = [12000, 15000, 18000, 24000, 35000, 50000, 70000];
employees_at_each_level = [3000, 2500, 1500, 1000, 400, 100, 25];

average_salary_level = mean(salary_levels);

employees_above_average = sum(employees_at_each_level(salary_levels > average_salary_level));
employees_below_average = sum(employees_at_each_level(salary_levels < average_salary_level));

total_annual_salary = sum(salary_levels .* employees_at_each_level);
total_employees = sum(employees_at_each_level);
average_salary_per_individual = total_annual_salary / total_employees;

fprintf('a. %d\n', average_salary_level);
fprintf('b. %d\t%d\n',employees_above_average, employees_below_average);
fprintf('c. %.2f\n',average_salary_per_individual);