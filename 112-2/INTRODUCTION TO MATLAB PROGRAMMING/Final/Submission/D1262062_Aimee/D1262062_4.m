clear student
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4) = struct('name', 'Mary', 'scores', [80,70,92,86]);
scores = [student(1).scores;student(2).scores;student(3).scores;student(4).scores]
avg = scores*[0.25; 0.25; 0.2; 0.3]
fprintf("scores = \n");
disp(scores)
fprintf("avg = \n");
disp(avg')
student(1).avg = avg(1);
student(2).avg = avg(2);
student(3).avg = avg(3);
student(4).avg = avg(4);