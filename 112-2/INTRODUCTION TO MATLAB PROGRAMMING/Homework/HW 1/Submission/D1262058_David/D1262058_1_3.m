close all; clear all;


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

math = 'math';
english = 'english';

math_avg = mean(score(1, :));
math_std = std(score(1, : ));
math_min = min(score(1, :));
math_max = max(score(1, : ));
fprintf('the mean score of %s is %3.2f \n',math, math_avg);
fprintf('the std score of %s is %3.2f \n',math, math_std);
fprintf('the min score of %s is %3.2f \n',math, math_min);
fprintf('the max score of %s is %3.2f \n',math, math_max);

english_avg = mean(score(2, :));
english_std = std(score(2, : ));
english_min = min(score(2, :));
english_max = max(score(2, : ));
fprintf('the mean score of %s is %3.2f \n',english, english_avg);
fprintf('the std score of %s is %3.2f \n',english, english_std);
fprintf('the min score of %s is %3.2f \n',english, english_min);
fprintf('the max score of %s is %3.2f \n',english, english_max);

save score_data N score 