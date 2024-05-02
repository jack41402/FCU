s = [12000, 15000, 18000, 24000, 35000, 50000, 70000];
e = [3000, 2500, 1500, 1000, 400, 100, 25];

a = mean(s);

ea = sum(e(s > a));
eb = sum(e(s < a));

total_annual_salary = sum(s .* e);
total_employees = sum(e);
average_salary_per_individual = total_annual_salary / total_employees;

fprintf('a. %d\n', a);
fprintf('b. %d\t%d\n',ea, eb);
fprintf('c. %.2f\n',average_salary_per_individual);
