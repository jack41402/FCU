unit = [6 2 1; 2 5 4; 4 3 2; 9 7 3];
quarter = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
sum(quarter)
g = unit*sum(quarter())*1000;
fprintf("Quarterly costs for materials: %d", g)
fprintf("Quarterly costs for labor %d", )