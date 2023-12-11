clear;clc;
salary = [12000 15000 18000 24000 35000 50000 70000] ;
employee = [3000 2500 1500 1000 400 100 25] ;
% Average salary level
average = mean(salary)

% The number of employees above and below the average
above = sum(employee.*(salary>average))
below = sum(employee.*(salary<average))

% The average salary earned by an individual
format bank
individual = sum(salary.*employee)/sum(employee)