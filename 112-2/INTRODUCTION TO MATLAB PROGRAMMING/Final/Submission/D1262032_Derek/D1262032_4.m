student(1)=struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2)=struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3)=struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4)=struct('name', 'Mary', 'scores', [80,70,92,86]);
scores(1, [1:4])=student(1).scores;
scores(2, [1:4])=student(2).scores;
scores(3, [1:4])=student(3).scores;
scores(4, [1:4])=student(4).scores;
scores
avg=0.25.*scores(:, 1)+0.25.*scores(:, 2)+0.2.*scores(:, 3)+0.3.*scores(:, 4);
avg=(avg)'
student=setfield(student, {1}, 'avg', avg(1, 1));
student=setfield(student, {2}, 'avg', avg(1, 2));
student=setfield(student, {3}, 'avg', avg(1, 3));
student=setfield(student, {4}, 'avg', avg(1, 4));
