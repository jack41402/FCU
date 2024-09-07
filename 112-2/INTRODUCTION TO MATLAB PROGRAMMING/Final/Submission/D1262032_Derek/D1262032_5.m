d=readcell('test_score1.xls');  
midterm=cell2mat(d(2:end, 5)); 
final=cell2mat(d(2:end, 6));
midterm_m=mean(midterm);
midterm_s=std(midterm);
m=mean(final);
s=std(final);
fprintf('Mean of mid-term scores: %.2f\n', midterm_m);
fprintf('Standard deviation of mid-term scores: %.2f\n', midterm_s);
fprintf('Mean of final scores: %.2f\n', m);
fprintf('Standard deviation of final scores: %.2f\n', s);
histogram(final, 'BinEdges', 60:5:100); 

