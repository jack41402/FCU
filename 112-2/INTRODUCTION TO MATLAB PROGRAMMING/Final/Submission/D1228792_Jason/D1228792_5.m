close all;clear all;
C = readcell('test_score1.xls');
mid = cell2mat(C(2:29,5))';
mmid = mean(mid);
stdmid = std(mid);
final = cell2mat(C(2:29,6))';
mfin = mean(final);
stdfin = std(final);
fprintf("Mean of mid-term scores: %.2f\n",mmid);
fprintf("Standard deviation of mid-term scores: %.2f\n",stdmid);
fprintf("Mean of final scores: %.2f\n",mfin);
fprintf("Standard deviation of final scores: %.2f\n",stdfin);
edges = 60:5:100;
histogram(final,edges)