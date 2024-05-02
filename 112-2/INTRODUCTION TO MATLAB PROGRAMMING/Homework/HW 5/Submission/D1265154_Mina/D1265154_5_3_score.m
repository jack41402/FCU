close all;
clear all;

N = input('Number of students: ');

% Initialize arrays to store scores and averages
names = cell(1, N);
scores = zeros(2, N);
avg = zeros(1, N);

% Input the name and score of each student and calculate the average score
for i = 1:N
    names{i} = input('Student name: ', 's');
    scores(1, i) = input('Math score: ');
    scores(2, i) = input('English score: ');
    avg(i) = mean(scores(:, i)); % Calculate the average score
end

% Output the average score of each student
for i = 1:N
    fprintf('The average score of %s is %.2f\n', names{i}, avg(i));
end

% Save the data to a file
save('score_data.mat', 'N', 'names', 'scores', 'avg');
