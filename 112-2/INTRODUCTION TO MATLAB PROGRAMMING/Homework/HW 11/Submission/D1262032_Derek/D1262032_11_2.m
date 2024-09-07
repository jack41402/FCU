format shortG
student(1)=struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2)=struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3)=struct('name', 'Betty', 'scores', [88,82,90,80]);
a(1, [1:4])=student(1).scores;
a(2, [1:4])=student(2).scores;
a(3, [1:4])=student(3).scores;
a
a(:, 5)=0.2.*a(:, 1)+0.2.*a(:, 2)+0.3.*a(:, 3)+0.3.*a(:, 4);
b=a(:, 5)
student=setfield(student, {1}, 'avg', b(1, 1));
student=setfield(student, {2}, 'avg', b(2, 1));
student=setfield(student, {3}, 'avg', b(3, 1));
