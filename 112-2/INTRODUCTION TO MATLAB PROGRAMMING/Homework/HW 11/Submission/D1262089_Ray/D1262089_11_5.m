% Step 1: Read the Excel file
data = readtable('test_score1.xls');
table = table2struct(data);
% Step 2: Calculate the average scores

a=mean([table.x____]);
b=mean([table.x_____1]);
c=mean([table.x_____2]);
table(29).x__='29';
table(29).x___1="Average score";
table(29).x____=a;
table(29).x_____1=b;
table(29).x_____2=c;

% Step 3: Export the table to a new Excel file
outputTable = struct2table(table);
writetable(outputTable, 'new.xls');


