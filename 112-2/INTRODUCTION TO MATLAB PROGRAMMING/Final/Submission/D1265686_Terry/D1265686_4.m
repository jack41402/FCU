student(1)=struct('name', 'Banny', 'scores', [85,80,92,78]);

student(2)=struct('name', 'Joey', 'scores', [80,85,90,88]);

student(3)=struct('name', 'Betty', 'scores', [88,82,90,80]);

student(4)=struct('name', 'Mary', 'scores', [80,70,92,86]);

scores(1, [1:4])=student(1).scores;

scores(2, [1:4])=student(2).scores;

scores(3, [1:4])=student(3).scores;

scores(4, [1:4])=student(4).scores;

scores

scores(:, 5)=0.25.*scores(:, 1)+0.25.*scores(:, 2)+0.2.*scores(:, 3)+0.3.*scores(:, 4);

b=scores(:, 5);

student=setfield(student, {1}, 'avg', b(1, 1));

student=setfield(student, {2}, 'avg', b(2, 1));

student=setfield(student, {3}, 'avg', b(3, 1));

student=setfield(student, {4}, 'avg', b(4, 1));


avg(1) = b(1,1);
avg(2) = b(2,1);
avg(3) = b(3,1);
avg(4) = b(4,1);

avg
