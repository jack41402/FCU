format compact
% student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
% student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
% student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
% student(4) = struct('name', 'Mary', 'scores', [80,70,92,86]);

scores = cell2mat({student.scores}')
weights = [0.25 0.25 0.2 0.3];

% Assign weighted averages to the avg field of each student
weighted_averages = num2cell(scores * weights');
[student(:).avg] = weighted_averages{:};

avg = [student.avg]