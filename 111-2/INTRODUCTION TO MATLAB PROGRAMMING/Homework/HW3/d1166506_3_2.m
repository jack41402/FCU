% initialize the array
wage = [5 , 5.5 , 6.5 , 6 , 6.25] ;
hour = [40 , 43 , 37 , 50 , 45] ;
output = [1000 , 1100 , 1000 , 1200 , 1100] ;

% Worker earn in the week
fprintf("a:\n") ;
for i=1:5
    fprintf("%.4f " , wage(i)*hour(i)) ;
end
fprintf("\n") ;

% Total salary paid out
fprintf("b:\n") ;
format("default")
total_salary = sum(wage.*hour) ;
fprintf("%.4f\n" , total_salary) ;

% Widgets were made
fprintf("c:\n") ;
format("default")
total_output = sum(output) ;
fprintf("%d\n" , total_output) ;

% Cost per Widget
fprintf("d:\n") ;
fprintf("%.4f\n" , total_salary/total_output) ;

% Hours per widget
fprintf("e:\n") ;
fprintf("%.4f\n" , sum(hour)/total_output) ;

% Max and min efficient
fprintf("f:\n")
max = -1 ;
min = 1e8 ;
for i=1:5
    temp = hour(i)/output(i) ;
    if (temp>max)
        max = temp ;
        max_i = i ;
    end
    if (temp<min)
        min = temp ;
        min_i = i ;
    end
end
fprintf("Most efficient: %d\n" , max_i) ;
fprintf("Least efficient: %d\n" , min_i) ;
