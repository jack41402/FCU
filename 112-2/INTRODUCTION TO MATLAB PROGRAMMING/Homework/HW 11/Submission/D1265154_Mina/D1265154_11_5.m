clear; clc;
filename = 'test_score1.xls';
scoreTable = readtable(filename, 'VariableNamingRule', 'preserve');
mean_x2 = mean(scoreTable{:, 4});
mean_x3 = mean(scoreTable{:, 5});
mean_x4 = mean(scoreTable{:, 6});
newRow_1 = {'x____', 'x_____1', 'x_____2', 'x____', 'x_____1', 'x_____2', 'x_____3', 'x_____4', 'x_____5'};
newRow = {'29', 'Average score','-', mean_x2, mean_x3, mean_x4, '' , '', ''};

scoreCell = [newRow_1;table2cell(scoreTable); newRow];

newScoreTable = cell2table(scoreCell, 'VariableNames', scoreTable.Properties.VariableNames);

writetable(newScoreTable, 'test_score2.xlsx');
