wage = [5 5.5 6.5 6 6.25] ;
hour = [40 43 37 50 45] ;
product = [1000 1100 1000 1200 1100] ;

% (a)
salary = wage.*hour

% (b)
fprintf("Total salary paid: ") ;
disp(sum(salary))

% (c)
units = sum(product)

% (d)
fprintf("Average cost per unit: ") ;
disp(sum(salary)/sum(units))

% (e)
fprintf("Average hours per unit: ") ;
disp(sum(hour)/sum(units))

% (f)
efficient = product./hour ;
fprintf("Most efficient: %d\n" , find(efficient==max(efficient))) ;
fprintf("Most inefficient: %d\n" , find(efficient==min(efficient))) ;

