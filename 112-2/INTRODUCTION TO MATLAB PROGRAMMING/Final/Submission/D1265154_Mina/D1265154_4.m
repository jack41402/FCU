clear student
student(1) = struct('name', 'Banny', 'scores', [85, 80, 92, 78]);
student(2) = struct('name', 'Joey', 'scores', [80, 85, 90, 88]);
student(3) = struct('name', 'Betty', 'scores', [88, 82, 90, 80]);
student(4) = struct('name', 'Mary', 'scores', [80, 70, 92, 86]);
fprintf('scores = \n');
for i = 1:length(student)
    fprintf('   %s\n', sprintf('%d ', student(i).scores));
end

for i = 1:length(student)
    scores = student(i).scores;
    avg_score = 0.25 * scores(1) + 0.25 * scores(2) + 0.2 * scores(3) + 0.3 * scores(4);
    student(i).avg = avg_score;
end
fprintf('avg = \n');
for i = 1:length(student)
    fprintf(' %.4f ', student(i).avg);
end

names = {student.name}';
scores = {student.scores}';
avgs = [student.avg]';
studentTable = table(names, scores, avgs, 'VariableNames', {'name', 'scores', 'avg'});
disp(studentTable);
