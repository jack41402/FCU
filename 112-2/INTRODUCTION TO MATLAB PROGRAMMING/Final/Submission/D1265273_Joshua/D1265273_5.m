clear all;
C = readcell("test_score1.xls");
a = cell2mat(C(2:29, 5));
b = cell2mat(C(2:29, 6));
avg_1 = mean(a);
avg_2 = mean(b);
std_1 = std(a);
std_2 = std(b);
fprintf("Mean of mid-term scores: %2.2f\n", avg_1)
fprintf("Standard deviation of mid-term scores: %2.2f\n", std_1)
fprintf("Mean of final scores: %2.2f\n", avg_2)
fprintf("Standard deviation of final scores: %2.2f\n", std_2)
histogram(b,60:5:100)
