unit_cost = [6000 2000 1000; 2000 5000 4000; 4000 3000 2000; 9000 7000 3000];
quarterly_volume = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];

quarterly_materials = sum(unit_cost(:,1).* quarterly_volume);
quarterly_labor = sum(unit_cost(:,2).* quarterly_volume);
quarterly_trans = sum(unit_cost(:,3).* quarterly_volume);

total_materials = sum(quarterly_materials);
total_labor = sum(quarterly_labor);
total_trans = sum(quarterly_trans);

total1 = sum(sum(unit_cost.* quarterly_volume(:,1)));
total2 = sum(sum(unit_cost.* quarterly_volume(:,2)));
total3 = sum(sum(unit_cost.* quarterly_volume(:,3)));
total4 = sum(sum(unit_cost.* quarterly_volume(:,4)));

fprintf('Quarterly costs for materials:%7d,%7d,%7d,%7d\n',quarterly_materials);
fprintf('Quarterly costs for labor:%7d,%7d,%7d,%7d\n',quarterly_labor);
fprintf('Quarterly costs for transportation:%6d,%6d,%6d,%6d\n\n',quarterly_trans);

fprintf('Total cost for materials: %d\n',total_materials);
fprintf('Total cost for labor: %d\n',total_labor);
fprintf('Total cost for transportation: %d\n\n',total_trans);

fprintf('The total quarterly costs:%7d,%7d,%7d,%7d\n',total1,total2,total3,total4)