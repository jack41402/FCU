C = readcell('test_score1.xls');
mid = [C{2:29,5}];
fprintf("Mean of mid-term scores: %.2f", mean(mid))
fprintf("\nStandrd deviation of mid-term scores: %.2f", std(mid))
fin = [C{2:29,6}];
fprintf("\nMean of final scores: %.2f", mean(fin))
fprintf("\nStandrd deviation of final scores: %.2f", std(fin))
a = 60:5:100;
histogram(fin,a)
