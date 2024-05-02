Salary_levels = [12000 15000 18000 24000 35000 50000 70000];
number = [3000 2500 1500 1000 400 100 25];
Total = Salary_levels.*number;
average = mean(Salary_levels);
fprintf("Answer: %d\n", average)
logic_vector = Salary_levels > average; 
above = logic_vector.*number;
sum(above);
logic_vector = Salary_levels < average; 
below = logic_vector.*number;
fprintf("Answer: %d above, %d below\nAnswer: %.2f\n", sum(above), sum(below), sum(Total)/sum(number))
