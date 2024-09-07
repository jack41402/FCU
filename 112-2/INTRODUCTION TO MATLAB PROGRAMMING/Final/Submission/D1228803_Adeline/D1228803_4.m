%D1228803_4

clear student;

student(1) = struct('name', 'Banny', 'scores', [85, 80, 92, 78]);
student(2) = struct('name', 'Joey', 'scores', [80, 85, 90, 88]);
student(3) = struct('name', 'Betty', 'scores', [88, 82, 90, 80]);
student(4) = struct('name', 'Mary', 'scores', [80, 70, 92, 86]);


a = reshape([student.scores], 4, [])';
disp('a = ');
disp(a);

avg = 0.25 * a(:, 1) + 0.25 * a(:, 2) + 0.2 * a(:, 3) + 0.3 * a(:, 4);
for i = 1:length(student)
    student(i).avg = avg(i);
end

disp('b = ');
disp(avg);