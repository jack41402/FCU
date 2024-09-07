clear student;
student(1) = struct('name', 'Banny', 'scores', [85, 80, 92, 78]);
student(2) = struct('name', 'Joey', 'scores', [80, 85, 90, 88]);
student(3) = struct('name', 'Betty', 'scores', [88, 82, 90, 80]);
a = cat(1, student.scores);
weights = [0.2; 0.2; 0.3; 0.3];
b = a * weights;
[student.avg] = deal(b(1), b(2), b(3));
disp('a:');
disp(a);
disp('b:');
for i = 1:length(b)
    fprintf('                      %.1f\n', b(i));
end
disp('Student structure with average scores:');
disp(student);


