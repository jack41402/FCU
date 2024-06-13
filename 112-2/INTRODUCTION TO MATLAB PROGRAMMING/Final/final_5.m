C = readcell("test_score1.xls");

midterm = cell2mat(C(2:end, 5));
final = cell2mat(C(2:end, 6));

mean_midterm = mean(midterm);
std_midterm = std(midterm);

mean_final = mean(final);
std_final = std(final);

fprintf('Mean of mid-term scores: %.2f\n', mean_midterm);
fprintf('Standard deviation of mid-term scores: %.2f\n', std_midterm);
fprintf('Mean of final scores: %.2f\n', mean_final);
fprintf('Standard deviation of final scores: %.2f\n', std_final);

edges = 60:5:100;
histogram(final, edges);