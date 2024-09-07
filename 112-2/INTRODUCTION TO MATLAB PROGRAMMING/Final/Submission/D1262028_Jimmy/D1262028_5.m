C = readcell("test_score1.xls");

avg_M = mean(cell2mat(C(2:29,5)));
std_M = std(cell2mat(C(2:29,5)));
avg_F = mean(cell2mat(C(2:29,6)));
std_F = std(cell2mat(C(2:29,6)));

fprintf("Mean of mid-term scores: %.2f", avg_M);
fprintf("\nStandard deviation of mid-term scores: %.2f", std_M);
fprintf("\nMean of mid-term scores: %.2f", avg_F);
fprintf("\nStandard deviation of mid-term scores: %.2f", std_F);

histogram(avg_F,60:5:100)