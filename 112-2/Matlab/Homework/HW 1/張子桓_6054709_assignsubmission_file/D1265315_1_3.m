%% 
close all; clear all;
% load score_data % input N score

N=input('   number of student:   ');
score=zeros(2,N);

% input the name and score of the student evaluate the average score
for i=1:N
    str1= input('student name:','s');
    eval(['name',int2str(i),'=str1;']);
%     if (i==1)
%         name=str1;
%     else
%         name=char(name,str1); % Create a character array.
%     end
score(1,i)=input('math score:   ');
score(2,i)=input('english score:   ');
avg(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
end

% output value
for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the average score of %s is %3.2f \n',str1,avg(i));
end

math_max = max(score(1, :));
math_min = min(score(1, :));
math_avg = mean(score(1, :));
math_std = std(score(1, :));
fprintf('\n\nmath max: %3.2f\n', math_max);
fprintf('\n\nmath min: %3.2f\n', math_min);
fprintf('\n\nmath avg: %3.2f\n', math_avg);
fprintf('\n\nmath std: %3.2f\n', math_std);

eng_max = max(score(2, :));
eng_min = min(score(2, :));
eng_avg = mean(score(2, :));
eng_std = std(score(2, :));
fprintf('\n\neng max: %3.2f\n', eng_max);
fprintf('\n\neng min: %3.2f\n', eng_min);
fprintf('\n\neng avg: %3.2f\n', eng_avg);
fprintf('\n\neng std: %3.2f\n', eng_std);

save score_data N score 