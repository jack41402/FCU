clear student;
student(1)=struct('name', 'Banny', 'scores', [85, 80, 92, 78]); 
student(2)=struct('name', 'Joey', 'scores', [80, 85, 90, 88]);
student(3)=struct('name', 'Betty', 'scores', [88, 82, 90, 80]);
student(4)=struct('name', 'Mary', 'scores', [80, 70, 92, 86]);
a = cat(1, student.scores);
weights = [0.25; 0.25; 0.2; 0.3];
b = a * weights;
[student.avg] = deal(b(1), b(2), b(3), b(3));
disp('scores = ');
disp(a);
disp('avg = ');
for i = 1:length(b)
    fprintf('   %.4f', b(i)); 
end
