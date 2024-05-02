income = [12000 15000 18000 24000 35000 50000 70000];
ne= [3000 2500 1500 1000 400 100 25];
total_income = 0;

average_income = mean(income)
above_average=income>average_income;
below_average=income<average_income;
num_above=sum(ne(above_average))
num_below=sum(ne(below_average))
total_sb =sum(income .*ne);
aspe =total_sb / sum(ne);
average_salary=sum(income .*ne)/sum(ne);
disp([num2str(aspe)])
