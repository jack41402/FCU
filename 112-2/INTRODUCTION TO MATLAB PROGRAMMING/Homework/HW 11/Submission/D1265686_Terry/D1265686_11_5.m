
S = readtable("test_score1.xls");

table = table2struct(S);

a=mean([table.x____]);

b=mean([table.x_____1]);

c=mean([table.x_____2]);

table(29).x__='29';

table(29).x___1="Average score";

table(29).x____=a;

table(29).x_____1=b;

table(29).x_____2=c;

S = struct2table(table);

writetable(S, "new_file.xls")
