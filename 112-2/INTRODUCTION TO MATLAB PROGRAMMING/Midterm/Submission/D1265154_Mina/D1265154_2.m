cost_product = [1, 2, 3, 4] * 1000;
cost_materials = [6, 2, 4, 9] * 1000;
cost_labor = [2, 5, 3, 7] * 1000;
cost_transportation = [1, 4, 2, 3] * 1000;
quarter1 = [10, 8, 12, 6];
quarter2 = [12, 7, 10, 4];
quarter3 = [13, 6, 13, 11];
quarter4 = [15, 4, 9, 5];
quarterly_cost_for_materials= sum(cost_materials .* [quarter1; quarter2; quarter3;quarter4], 2)
quarterly_cost_for_labor= sum(cost_labor .* [quarter1; quarter2; quarter3;quarter4], 2)
quarterly_cost_for_transportation= sum(cost_transportation .* [quarter1; quarter2; quarter3;quarter4], 2)



total_cost_year = sum([sum(quarter1 .* cost_materials), sum(quarter1 .* cost_labor), sum(quarter1 .* cost_transportation); 
                       sum(quarter2 .* cost_materials), sum(quarter2 .* cost_labor), sum(quarter2 .* cost_transportation); 
                       sum(quarter3 .* cost_materials), sum(quarter3 .* cost_labor), sum(quarter3 .* cost_transportation);
                       sum(quarter4 .* cost_materials), sum(quarter4 .* cost_labor), sum(quarter4 .* cost_transportation)]);
fprintf('(b)materials: $%d, labor: $%d, transportation: $%d\n', total_cost_year(1), total_cost_year(2), total_cost_year(3));





total_cost_quarter1 = sum(quarter1 .* [cost_materials; cost_labor; cost_transportation], 'all');
total_cost_quarter2 = sum(quarter2 .* [cost_materials; cost_labor; cost_transportation], 'all');
total_cost_quarter3 = sum(quarter3 .* [cost_materials; cost_labor; cost_transportation], 'all');
total_cost_quarter4 = sum(quarter4 .* [cost_materials; cost_labor; cost_transportation], 'all');
disp('(c) Total quarterly costs:');
disp(['Quarter 1: $' num2str(total_cost_quarter1)]);
disp(['Quarter 2: $' num2str(total_cost_quarter2)]);
disp(['Quarter 3: $' num2str(total_cost_quarter3)]);
disp(['Quarter 4: $' num2str(total_cost_quarter4)]);




