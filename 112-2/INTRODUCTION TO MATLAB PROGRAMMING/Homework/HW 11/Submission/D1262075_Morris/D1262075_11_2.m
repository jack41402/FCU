clear student
% clear student 
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]); 
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]); 
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);

s1 = student(1).scores;
s2 = student(2).scores;
s3 = student(3).scores;
s = [s1; s2; s3];

fprintf('a = \n');
disp(s);

avg1 = s1(1).*0.2 + s1(2).*0.2 + s1(3).*0.3 + s1(4).*0.3;
avg2 = s2(1).*0.2 + s2(2).*0.2 + s2(3).*0.3 + s2(4).*0.3;
avg3 = s3(1).*0.2 + s3(2).*0.2 + s3(3).*0.3 + s3(4).*0.3;

b = [avg1; avg2; avg3];

fprintf('b = \n');
for i = 1:length(b)
    fprintf('                       %g\n', b(i)); 
end
a = cat(1,student.scores)
c = a * [0.2; 0.2; 0.3; 0.3]
[student.avg] = deal(b(1), b(2), b(3));
student