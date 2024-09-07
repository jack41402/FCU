clear all;
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4) = struct('name', 'Mary','scores',[80,70,92,86]);
scores(1, 1:4) = student(1).scores;
scores(2, 1:4) = student(2).scores;
scores(3, 1:4) = student(3).scores;
scores(4, 1:4) = student(4).scores;
scores

avg_1 = 0.25.*student(1).scores(1,1)+0.25.*student(1).scores(1,2)+0.2.*student(1).scores(1,3)+0.3.*student(1).scores(1,4);
avg_2 = 0.25.*student(2).scores(1,1)+0.25.*student(2).scores(1,2)+0.2.*student(2).scores(1,3)+0.3.*student(2).scores(1,4);
avg_3 = 0.25.*student(3).scores(1,1)+0.25.*student(3).scores(1,2)+0.2.*student(3).scores(1,3)+0.3.*student(3).scores(1,4);
avg_4 = 0.25.*student(4).scores(1,1)+0.25.*student(4).scores(1,2)+0.2.*student(4).scores(1,3)+0.3.*student(4).scores(1,4);
avg(1,1) = avg_1;
avg(1,2) = avg_2;
avg(1,3) = avg_3;
avg(1,4) = avg_4;
avg