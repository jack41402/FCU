% Initialize variables
clear;
close all;

% Input the number of students
N = input('Enter the number of students: ');

% Initialize arrays to store data
names = cell(1, N);
scores = zeros(2, N);
avg_scores = zeros(1, N);
GPA = zeros(1, N);


for i = 1:N
    names{i} = input('Enter student name: ', 's');
    scores(1, i) = input('Enter math score: ');
    scores(2, i) = input('Enter English score: ');
end

for i = 1:N
    avg_scores(i) = mean(scores(:, i));
    if avg_scores(i) >= 90
        GPA(i) = 4.0;
    elseif avg_scores(i) >= 80
        GPA(i) = 3.0;
    elseif avg_scores(i) >= 70
        GPA(i) = 2.0;
    elseif avg_scores(i) >= 60
        GPA(i) = 1.0;
    else
        GPA(i) = 0.0;
    end
end


disp('Average Scores and GPAs:');
for i = 1:N
    fprintf('Student: %s, Average Score: %.2f, GPA: %.2f\n', names{i}, avg_scores(i), GPA(i));
end


save('score_data2.mat', 'N', 'names', 'scores', 'avg_scores', 'GPA');
