c = readcell('test_score1.xls');
mean_x2 = mean(scoreTable{:, 5});
fprintf('Mean of mid-term scores: %.2f \n',mean_x2);
sta = std(scoreTable{:, 5});
fprintf('Standard deviation of mid-term scores: %.2f \n',sta);

mean_x3 = mean(scoreTable{:, 6});
fprintf('Mean of final scores: %.2f \n',mean_x3);

sta_2 = std(scoreTable{:, 6});
fprintf('Standard deviation of mid-term scores: %.2f \n',sta_2);

bar(sta_2,mean_x3,sta);


