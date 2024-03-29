format("long")
materials = [7000 3000 9000 2000 6000] ;
labor = [3000 1000 4000 5000 2000] ;
transportation = [2000 3000 5000 4000 1000] ;
season = [16 14 10 12 ; 12 15 11 13 ; 8 9 7 11 ; 14 13 15 17 ; 13 16 12 18] ;

material_sum = sum(season.*materials');
labor_sum = sum(season.*labor');
transportation_sum = sum(season.*transportation');

%  (a) the cost of materials, labor, and transportation for each season.
fprintf("(a)\n")
fprintf("                1st     2nd     3rd     4th\n");
fprintf("materials:      %d  %d  %d  %d\n", material_sum);
fprintf("labor:          %d  %d  %d  %d\n", labor_sum);
fprintf("transportation: %d  %d  %d  %d\n", transportation_sum);

%  (b) the total cost of materials, labor, and transportation for each year.
fprintf("\n(b)\n") ;
fprintf("materials:     %d\n", sum(material_sum));
fprintf("labor:          %d\n", sum(labor_sum));
fprintf("transportation: %d\n", sum(transportation_sum));

%  (c) total costs of each season.
fprintf("\n(c)\n")
fprintf("1st     2nd     3rd     4th\n");
fprintf("%d  %d  %d  %d\n", sum(season.*(materials + labor + transportation)'))
