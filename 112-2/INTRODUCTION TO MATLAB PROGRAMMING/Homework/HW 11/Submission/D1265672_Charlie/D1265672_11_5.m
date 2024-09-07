data = readtable('test_score1.xls');

tab = table2struct(data);
a=mean([tab.x____]);
b=mean([tab.x_____1]);
c=mean([tab.x_____2]);
tab(29).x__='29';
tab(29).x___1="Average score";
tab(29).x____=a;
tab(29).x_____1=b;
tab(29).x_____2=c;
data = struct2table(tab);
writetable(data, "new_file.xls")