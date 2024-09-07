filename = 'test_score1.xls';

data = readcell(filename);

mid_term_scores = cell2mat(data(2:end, 5)); 
final_scores = cell2mat(data(2:end, 6)); 

mean_midterm = mean(mid_term_scores);
std_midterm = std(mid_term_scores);

mean_final = mean(final_scores);
std_final = std(final_scores);

edges = 60:5:100;

figure;
histogram(final_scores, edges);
xlabel('Score Range');
ylabel('Number of Students');
title('Distribution of Final Scores');

fprintf('Mean of mid-term scores: %.2f\n', mean_midterm);
fprintf('Standard deviation of mid-term scores: %.2f\n', std_midterm);
fprintf('Mean of final scores: %.2f\n', mean_final);
fprintf('Standard deviation of final scores: %.2f\n', std_final);
