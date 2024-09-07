clear all;
a = table2struct(readtable("test_score1.xls"));
avg_1 = mean(cat(1,a.x____));
avg_2 = mean(cat(1,a.x_____1));
avg_3 = mean(cat(1,a.x_____2));
a(29) = struct('x__', '29', 'x___1', 'Average_score', 'x___2', ' ', 'x____', avg_1, 'x_____1', avg_2,'x_____2', avg_3, 'x_____3', ' ', 'x_____4', ' ', 'x_____5', ' ');
writetable(struct2table(a),'test_score2.xls');
