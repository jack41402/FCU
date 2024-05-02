income = [12000 15000 18000 24000 35000 50000 70000];
employee = [3000, 2500, 1500, 1000, 400, 100, 25];
average = mean(income);
fprintf('average: %d\n', average);

above = sum(employee(income > average));
below = sum(employee(income < average));
fprintf('above: %d\n', above);
fprintf('below: %d\n', below);

total_income = sum(income .* employee);
total_employee = sum(employee);
average_salary = total_income / total_employee;
fprintf('%.2f\n', average_salary);
