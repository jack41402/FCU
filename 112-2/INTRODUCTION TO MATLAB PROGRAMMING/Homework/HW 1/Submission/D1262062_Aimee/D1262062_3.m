N = input('');
names = cell(1, N);
for i = 1:N
    names{i} = input('student name: ', 's');
    score(1, i) = input('math score: ');
    score(2, i) = input('english score: ');
    avg(i) = mean(score(:, i));
end
for i = 1:N
    fprintf('the average score of %s is %3.2f \n', names{i}, avg(i));
end
math_min = min(score(1, :));
math_max = max(score(1, :));
math_avg = mean(score(1, :));
math_std = std(score(1, :));
students = struct('Name', {}, 'MathScore', {}, 'EnglishScore', {}, 'Average', {});
close all; 
clear all;

N = input('Number of students: ');

names = cell(1, N);
score = zeros(2, N);
avg = zeros(1, N);

for i = 1:N
    names{i} = input('Student name: ', 's');
    score(1, i) = input('Math score: ');
    score(2, i) = input('English score: ');
    avg(i) = mean(score(:, i));
end

fprintf('\n\nStatistics for Math scores:\n');
display_statistics(score(1, :));

fprintf('\n\nStatistics for English scores:\n');
display_statistics(score(2, :));

save score_data names score;

function display_statistics(data)
    fprintf('Std: %3.2f\n', std(data));
    fprintf('Avg: %3.2f\n', mean(data));
    fprintf('Max: %3.2f\n', max(data));
    fprintf('Min: %3.2f\n', min(data));
end
