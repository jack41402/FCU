clear student
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]); 
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]); 
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4) = struct('name', 'Mary', 'scores', [80,70,92,86]);
a = cat(1,student.scores);
fprintf('scores = \n');
disp(a);

s1 = student(1).scores;
s2 = student(2).scores;
s3 = student(3).scores;
s4 = student(4).scores;
avg1 = s1(1).*0.25 + s1(2).*0.25 + s1(3).*0.2 + s1(4).*0.3;
avg2 = s2(1).*0.25 + s2(2).*0.25 + s2(3).*0.2 + s2(4).*0.3;
avg3 = s3(1).*0.25 + s3(2).*0.25 + s3(3).*0.2 + s3(4).*0.3;
avg4 = s4(1).*0.25 + s4(2).*0.25 + s4(3).*0.2 + s4(4).*0.3;
b = [avg1,avg2,avg3,avg4];
fprintf('avg = \n');
disp(b);

for i = 1:length(student)
    student(i).avg = b(i);
end

disp(student);