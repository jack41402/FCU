close all;clear all;
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4) = struct('name', 'Mary', 'scores', [80,70,92,86]);
scores = cat(1,student.scores)
c = [0.25;0.25;0.2;0.3];
b = scores * c;
avg = b'
student(1).avg = b(1);
student(2).avg = b(2);
student(3).avg = b(3);
student(4).avg = b(4);