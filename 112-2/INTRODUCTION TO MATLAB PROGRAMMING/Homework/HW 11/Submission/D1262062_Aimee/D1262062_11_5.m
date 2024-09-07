students = table2struct(readtable('test_score1.xls'));
student2 = students;
student2(29).x__ = '29';
student2(29).x___1 = 'Average scores';
student2(29).x___2 = '-';
score1 = [students.x____];
student2(29).x____ = mean(score1);
score2 = [students.x_____1];
student2(29).x_____1= mean(score2);
score3 = [students.x_____2];
student2(29).x_____2 = mean(score3);

writetable(struct2table(student2), 'output.xls')