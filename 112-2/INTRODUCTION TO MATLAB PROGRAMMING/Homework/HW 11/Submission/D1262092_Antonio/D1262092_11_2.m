clear all;

student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);

a(1, 1:4) = student(1).scores;
a(2, 1:4) = student(2).scores;
a(3,1:4) = student(3).scores;

a

avg_1 = 0.2.*student(1).scores(1,1)+0.2.*student(1).scores(1,2)+0.3.*student(1).scores(1,3)+0.3.*student(1).scores(1,4);
avg_2 = 0.2.*student(2).scores(1,1)+0.2.*student(2).scores(1,2)+0.3.*student(2).scores(1,3)+0.3.*student(2).scores(1,4);
avg_3 = 0.2.*student(3).scores(1,1)+0.2.*student(3).scores(1,2)+0.3.*student(3).scores(1,3)+0.3.*student(3).scores(1,4);

b(1,1) = avg_1;
b(2,1) = avg_2;
b(3,1) = avg_3;

fprintf("b=\n            %d\n            %2.1f\n            %d\n", b(1,1), b(2,1), b(3,1))
student(1).avg = avg_1;
student(2).avg = avg_2;
student(3).avg = avg_3;
