close all; clear all;
%load score_data % input N score

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
disp(N)
for i=1:N
    eval(['str1=name',int2str(i),';']);
    fprintf("score: %3.2f %3.2f\n", score(1, i), score(2, i))
 %fprintf('the score of math %s is %3.2f and the score of english is %3.2f \n',str1,score(1,i), score(2,i));
end
save score_data N score 