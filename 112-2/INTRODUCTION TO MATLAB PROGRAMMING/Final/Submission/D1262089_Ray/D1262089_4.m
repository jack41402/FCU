clc
clear all
clear student
student(1)=struct('name','Banny','scores',[85,80,92,78]);
student(2)=struct('name','Joey','scores',[80,85,90,88]);
student(3)=struct('name','Betty','scores',[88,82,90,80]);
student(4)=struct('name','Mary','scores',[80,70,92,86]);
% (a) Get the values of the scores of every student
scores=[student(1).scores;student(2).scores;student(3).scores;student(4).scores]
% (b) Calculate the average score of each student
for i = 1:numel(student)
    score = student(i).scores;
    avg_score (i)= 0.25 * score(1) + 0.25 * score(2) + 0.2 * score(3) + 0.3 * score(4);
    
end
avg =avg_score
% (c) Add a field named ‘avg’ for the Average score of the student
for i = 1:numel(student)
    student(i).avg = avg_score(i);
end
