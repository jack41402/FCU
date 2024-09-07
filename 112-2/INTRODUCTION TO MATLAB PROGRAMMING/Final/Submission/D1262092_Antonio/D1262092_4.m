clear all;
student(1) = struct('name','Banny','scores',[85,80,92,78]);
student(2) = struct('name','Joey','scores',[80,85,90,88]);
student(3) = struct('name','Betty','scores',[88,82,90,80]);
student(4) = struct('name','Mary','scores',[80,70,92,86]);

%a
scores = [student(1).scores;
          student(2).scores;
          student(3).scores;
          student(4).scores]
avgCal = [0.25,0.25,0.2,0.3];
avg = [sum(student(1).scores.*avgCal),sum(student(2).scores.*avgCal),sum(student(3).scores.*avgCal),sum(student(4).scores.*avgCal)]
student(1) = struct('name','Banny','scores',[85,80,92,78],'avg',avg[1]);
student(2) = struct('name','Joey','scores',[80,85,90,88],'avg',avg[2]);
student(3) = struct('name','Betty','scores',[88,82,90,80],'avg',avg[3]);
student(4) = struct('name','Mary','scores',[80,70,92,86],'avg',avg[4]);