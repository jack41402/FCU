close all; clear all;
load score_data % input N score
for i=1:N
avge(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
gpa(i) = (avge(i) < 40) .* 0;
gpa(i) = gpa(i) + (avge(i) >= 40 & avge(i) <= 59) .* 1.0;
gpa(i) = gpa(i) + (avge(i) >= 60 & avge(i) <= 62) .* 1.7;
gpa(i) = gpa(i) + (avge(i) >= 63 & avge(i) <= 66) .* 2.0;
gpa(i) = gpa(i) + (avge(i) >= 67 & avge(i) <= 69) .* 2.3;
gpa(i) = gpa(i) + (avge(i) >= 70 & avge(i) <= 72) .* 2.7;
gpa(i) = gpa(i) + (avge(i) >= 73 & avge(i) <= 76) .* 3.0;
gpa(i) = gpa(i) + (avge(i) >= 77 & avge(i) <= 79) .* 3.3;
gpa(i) = gpa(i) + (avge(i) >= 80 & avge(i) <= 84) .* 3.7;
gpa(i) = gpa(i) + (avge(i) >= 85 & avge(i) <= 89) .* 4.0;
gpa(i) = gpa(i) + (avge(i) >= 90 & avge(i) <= 100) .* 4.3;
end
% output value

for i=1:N
 fprintf('the average score of student%d is %3.2f \n',i,avge(i));
 fprintf('the GPA of student%d is %3.1f \n',i,gpa(i));
end
save  score_data2 N score gpa