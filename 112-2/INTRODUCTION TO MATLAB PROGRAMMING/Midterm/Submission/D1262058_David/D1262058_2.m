cost = [6 2 1; 2 5 4; 4 3 2; 9 7 3];
volume = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
a = cost' * volume * 1000;

fprintf("Quarterly costs for materials: %d, %d, %d, %d\n", a(1,1), a(1,2), a(1,3),a(1,4));
fprintf("Quarterly costs for labor: %d, %d, %d, %d\n", a(2,1), a(2,2), a(2,3),a(2,4));
fprintf("Quarterly costs for transportation: %d, %d, %d, %d\n", a(3,1), a(3,2), a(3,3),a(3,4));
fprintf("Total costs for materials: %d\n", sum(a(1,:)));
fprintf("Total costs for labor: %d\n", sum(a(2,:)));
fprintf("Total costs for transportation: %d\n", sum(a(3,:)));
fprintf("Total quarterly costs: %d, %d, %d, %d", sum(a(:, 1)), sum(a(:,2)), sum(a(:, 3)), sum(a(:, 4)))
