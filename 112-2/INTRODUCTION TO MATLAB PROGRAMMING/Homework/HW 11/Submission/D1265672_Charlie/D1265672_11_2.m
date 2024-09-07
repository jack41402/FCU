a = [85 80 92 78; 80 85 90 88; 88 82 90 80]

weights = [0.2, 0.2, 0.3, 0.3];
b = a * weights'

student(1).name = 'Banny';
student(1).scores = a(1,:);
student(1).avg = b(1);

student(2).name = 'Joey';
student(2).scores = a(2,:);
student(2).avg = b(2);

student(3).name = 'Betty';
student(3).scores = a(3,:);
student(3).avg = b(3);

c = struct2table(student);