student(1).name = 'Banny';
student(1).scores = [85 80 92 78];

student(2).name = 'Joey';
student(2).scores = [80 85 90 88];

student(3).name = 'Betty';
student(3).scores = [88 82 90 80];

student(4).name = 'Mary';
student(4).scores = [80 70 92 86];

weights = [0.25 0.25 0.2 0.3];

for i = 1:length(student)
    student(i).avg = sum(student(i).scores .* weights);
end

fprintf('scores = \n')
for i = 1:length(student)
    fprintf('    %s\n', num2str(student(i).scores));
end
fprintf('avg = \n') 
for i = 1:length(student)   
    fprintf('   %.4f', student(i).avg);
end
