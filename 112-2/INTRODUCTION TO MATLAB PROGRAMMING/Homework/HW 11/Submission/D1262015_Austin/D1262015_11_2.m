clear student
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
a=[student(1).scores;student(2).scores;student(3).scores]

s1=student(1).scores;
s2=student(2).scores;
s3=student(3).scores;
avg1=0.2.*s1(1)+0.2.*s1(2)+0.3.*s1(3)+0.3.*s1(4);
avg2=0.2.*s2(1)+0.2.*s2(2)+0.3.*s2(3)+0.3.*s2(4);
avg3=0.2.*s3(1)+0.2.*s3(2)+0.3.*s3(3)+0.3.*s3(4);

b=[avg1; avg2; avg3]

student(1).avg=avg1;
student(2).avg=avg2;
student(3).avg=avg3;

save('avg','student')
