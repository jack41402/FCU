Student = table2struct(readtable("test_score1.xls"));
a = mean(Student(1).x____);
b = mean(Student(2).x____1);
c = mean(Student(3).x____2);
Student(29)= struct('x__','29','x___1','Average score','x___2','-','x____',a,'x____1',b,'x____2',c);
writetable(struct2table(student2), 'output.xls');