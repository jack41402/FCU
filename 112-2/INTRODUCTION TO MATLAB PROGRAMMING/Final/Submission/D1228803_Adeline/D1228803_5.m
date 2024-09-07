clear;

C = readcell('test_score1.xls')

%scoreTable = readtable('test_score1.xls');
scoreStruct = table2struct(C);
meanColumn1 = mean([scoreStruct.x_____]);
meanColumn2 = mean([scoreStruct.x_____1]);
meanColumn3 = mean([scoreStruct.x_____2]);

newRow = struct('x__', '29', 'x___1', 'Average score', 'x___2', '-', 'x_____', meanColumn1, 'x____1', meanColumn2, 'x____2', meanColumn3, 'x____3');

scoreStruct(end + 1) = newRow;
updateStoreTable = struct2table(scoreStruct);

histogram(60, 100);