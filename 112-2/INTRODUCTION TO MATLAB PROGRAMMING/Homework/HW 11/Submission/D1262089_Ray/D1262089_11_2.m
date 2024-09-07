clear student
student(1)=struct('name','Banny','scores',[85,80,92,78]);
student(2)=struct('name','Joey','scores',[80,85,90,88]);
student(3)=struct('name','Betty','scores',[88,82,92,80]);
% (a) Get the values of the scores of every student
a=[student(1).scores;student(2).scores;student(3).scores]
% (b) Calculate the average score of each student
for i = 1:numel(student)
    scores = student(i).scores;
    avg_score (i)= 0.2 * scores(1) + 0.2 * scores(2) + 0.3 * scores(3) + 0.3 * scores(4);
    
end
b=avg_score'
% (c) Add a field named ‘avg’ for the Average score of the student
for i = 1:numel(student)
    scores = student(i).scores;
    student(i).avg = avg_score(i);
end