cost=[6 2 1; 2 5 4; 4 3 2; 9 7 3];
volume=[10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];

materials=sum(cost(:, 1).*volume).*1000;
labor=sum(cost(:, 2).*volume).*1000;
transportation=sum(cost(:, 3).*volume).*1000;

fprintf("Quarterly costs for materials: ");
fprintf("%d, %d, %d, %d\n", materials);

fprintf("Quarterly costs for labor: ");
fprintf("%d, %d, %d, %d\n", labor);

fprintf("Quarterly costs for transportation: ");
fprintf("%d, %d, %d, %d\n", transportation);

fprintf("\nTotal costs for materials: %d\n", sum(materials));
fprintf("Total costs for labor: %d\n", sum(labor));
fprintf("Total costs for transportation: %d\n", sum(transportation));

fprintf("\nThe total quarterly costs: %d, %d, %d, %d\n", materials+labor+transportation);