clear;
Test=readcell("test_score1.xls");
X=cell2mat(Test(2:29, 5));
Y=cell2mat(Test(2:29, 6));
meanofmid=mean(X);
stdofmid=std(X);
meanoff=mean(Y);
stdoff=std(Y);

fprintf("Mean of mid-term scores: %.2f\n", meanofmid);
fprintf("Standard deviation of mid-term scores: %.2f\n", stdofmid);
fprintf("Mean of final scores: %.2f\n", meanoff);
fprintf("Standard deviation of final scores: %.2f\n", stdoff);

histogram(X)

