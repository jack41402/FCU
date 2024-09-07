c = readcell('test_score1.xls');

m = cell2mat ( c(2:29,5) );

f = cell2mat ( c(2:29,6) );

fprintf('Mean of mid-term scores: %.2f\n', mean(m) );

fprintf('Standard deviation of mid-term scores: %.2f\n', std(m) );

fprintf('Mean of final scores: %.2f\n', mean(f) );

fprintf('Standard deviation of final scores: %.2f\n', std(f) );

histogram(f , 60:5:100);