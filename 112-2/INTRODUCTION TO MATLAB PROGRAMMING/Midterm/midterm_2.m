material = [6 2 4 9];
labor = [2 5 3 7];
transportation = [1 4 2 3];
product = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
C = [material; labor; transportation];

% quarterly costs for materials, labor, and transportation
fprintf("Quarterly costs for materials: %d, %d, %d, %d\n", 1000*material * product);
fprintf("Quarterly costs for labor: %d, %d, %d, %d\n", 1000*labor * product);
fprintf("Quarterly costs for transportation: %d, %d, %d, %d\n", 1000*transportation * product);
fprintf("\n");

% the total material, labor, and transportation costs for the year
fprintf("Total costs for materials: %d\n", 1000*sum(material * product));
fprintf("Total costs for labor: %d\n", 1000*sum(labor * product));
fprintf("Total costs for transportation: %d\n", 1000*sum(transportation * product));
fprintf("\n");

% the total quarterly costs
fprintf("The total quarterly costs: %d, %d, %d, %d\n", 1000*sum(C * product));
