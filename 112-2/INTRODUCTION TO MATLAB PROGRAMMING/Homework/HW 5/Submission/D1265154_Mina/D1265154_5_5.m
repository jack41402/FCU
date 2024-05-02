
salary_levels = [12000, 15000, 18000, 24000, 35000, 50000, 70000];
num_employees = [3000, 2500, 1500, 1000, 400, 100, 25];


average_salary_level = mean(salary_levels);
disp(['Average salary level: $', num2str(average_salary_level)]);


above_average = salary_levels > average_salary_level;
below_average = salary_levels < average_salary_level;

num_above = sum(num_employees(above_average));
num_below = sum(num_employees(below_average));

disp(['Number of employees above average salary level: ', num2str(num_above)]);
disp(['Number of employees below average salary level: ', num2str(num_below)]);


total_salary_bill = sum(salary_levels .* num_employees);

average_salary_per_employee = total_salary_bill / sum(num_employees);
disp(['Average salary earned by an individual in the company: $', num2str(average_salary_per_employee)]);
