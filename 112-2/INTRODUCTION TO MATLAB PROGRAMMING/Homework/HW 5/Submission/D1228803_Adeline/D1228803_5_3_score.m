close all;
clear all;

N = input('Number of students: ');

score = zeros(2, N);
names = cell(1, N);

for i = 1:N
    names{i} = input('Student name: ', 's');
    score(1, i) = input('Math score: ');
    score(2, i) = input('English score: ');
end

save('score_data.mat', 'N', 'score', 'names');
