cost=[6 2 1; 2 5 4; 4 3 2; 9 7 3];
number=[10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];

fprintf("quarterly cost for materials: ");
material=sum(cost(:, 1).*number*1000);
fprintf("%d, %d, %d, %d", material)
fprintf("\nquarterly cost for labor: ");
labor=sum(cost(:, 2).*number.*1000);
fprintf("%d, %d, %d, %d", labor)
fprintf("\nquarterly cost for transportation: ");
transportation=sum(cost(:, 3).*number.*1000);
fprintf("%d, %d, %d, %d", transportation)
fprintf("\n\n");
fprintf("Total costs for materials: %d\n", sum(material));
fprintf("Total costs for labor: %d\n", sum(labor));
fprintf("Total costs for transportation: %d\n", sum(transportation));
total=material+labor+transportation;
fprintf("\nThe total quarterly costs: ")
fprintf("%d, %d, %d, %d\n", total);