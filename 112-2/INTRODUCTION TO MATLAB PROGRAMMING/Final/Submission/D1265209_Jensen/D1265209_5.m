clear C;
C = table2struct(readtable("test_score1.xls"));

a= mean(cat(1,C.x_____1));
fprintf('Mean of mid-term scores: %.2f\n',a)
b= std(cat(1,C.x_____1));
fprintf('Standard deviation of mid-term scores: %.2f\n', b);
c= mean(cat(1,C.x_____2));
fprintf('Mean of final scores: %.2f\n', c);
d= std(cat(1,C.x_____2)); 
fprintf('Standard deviation of final scores: %.2f\n', d);

e=cat(1,C.x_____2);

figure;
histogram(e,[60:5:100])
