C = readcell('test_score1.xls');
midterm_scores = cell2mat(C(2:end, 5));
final_scores = cell2mat(C(2:end, 6));
std1 = std(midterm_scores);
std2 = std(final_scores);
mean1 = mean(midterm_scores);
mean2 = mean(final_scores);
fprintf('Mean of mid-term scores: %.2f\n', mean1);
fprintf('Standard devitation of mid-term scores: %.2f\n',std1);
fprintf('Mean of final scores: %.2f\n', mean2);
fprintf('Standard devitation of final scores: %.2f\n',std2);
edges = 60:5:100; 
[counts, ~] = histcounts(final_scores, edges);
group_labels = {'60', '65', '70', '75', '80', '85', '90', '95', '100'};
histogram(final_scores,edges);



