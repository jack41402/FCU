clear student
student(1) = struct('name', 'Banny', 'scores', [85, 80, 92, 78]);
student(2) = struct('name', 'Joey', 'scores', [80, 85, 90, 88]);
student(3) = struct('name', 'Betty', 'scores', [88, 82, 90, 80]);

a = [student(1).scores; student(2).scores; student(3).scores]
b = [0.2; 0.2; 0.3; 0.3];
b = a * b
student(1).avg = b(1,1);
student(2).avg = b(2,1);
student(3).avg = b(3,1);
save('b','student');
c = student;