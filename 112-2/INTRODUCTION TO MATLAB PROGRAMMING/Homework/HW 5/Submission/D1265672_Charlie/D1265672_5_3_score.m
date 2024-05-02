score = zeros(2, 10);
N=input('   number of student:   ');
for i = 1:N
    prompt = sprintf('Enter Math score for student %d: ', i);
    score(1,i) = input(prompt);
    prompt = sprintf('Enter English score for student %d: ', i);
    score(2,i) = input(prompt);
end

save('score_data.mat', 'N', 'score');