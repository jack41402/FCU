clear;

scoreTable = readtable('test_score1.xls');
scoreStruct = table2struct(scoreTable);

meanColumn1 = mean([scoreStruct.x_____]);
meanColumn2 = mean([scoreStruct.x_____1]);
meanColumn3 = mean([scoreStruct.x_____2]);
newRow = struct('x__', '29','x___1', 'Average score','x___2', '-','x_____', meanColumn1,'x_____1', meanColumn2,'x_____2', meanColumn3,'x_____3', '','x_____4', ' ','x_____5', '');

scoreStruct(end+1) = newRow;
updatedScoreTable = struct2table(scoreStruct);