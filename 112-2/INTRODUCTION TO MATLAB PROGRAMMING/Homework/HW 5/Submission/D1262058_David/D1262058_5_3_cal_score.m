close all; clear all;
load score_data % input N score
for i=1:N
avg(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
gpa(i) = (avg(i) < 40) .* 0;
gpa(i) = gpa(i) + (avg(i) >= 40 & avg(i) <= 59) .* 1.0;
gpa(i) = gpa(i) + (avg(i) >= 60 & avg(i) <= 62) .* 1.0;
gpa(i) = gpa(i) + (avg(i) >= 63 & avg(i) <= 66) .* 2.0;
gpa(i) = gpa(i) + (avg(i) >= 67 & avg(i) <= 69) .* 2.3;
gpa(i) = gpa(i) + (avg(i) >= 70 & avg(i) <= 72) .* 2.7;
gpa(i) = gpa(i) + (avg(i) >= 73 & avg(i) <= 76) .* 3.0;
gpa(i) = gpa(i) + (avg(i) >= 77 & avg(i) <= 79) .* 3.3;
gpa(i) = gpa(i) + (avg(i) >= 80 & avg(i) <= 84) .* 3.7;
gpa(i) = gpa(i) + (avg(i) >= 85 & avg(i) <= 89) .* 4.0;
gpa(i) = gpa(i) + (avg(i) >= 90 & avg(i) <= 100) .* 4.3;
end
% output value

%for i=1:N
% fprintf('the average score of student%d is %3.2f \n',i,avg(i));
% fprintf('the GPA of student%d is %3.1f \n',i,gpa(i));
%end
save  score_data2 N avg gpa score 