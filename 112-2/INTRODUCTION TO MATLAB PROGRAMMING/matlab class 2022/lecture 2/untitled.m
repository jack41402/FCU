close all; clear all;

%% A simple example using MATLAB
% load score_data % input N score

N=input('   number of student:   ');
score=zeros(2,N);

% input the name and score of the student evaluate the average score
for i=1:N
    str1= input('student name:','s');
    eval(['name',int2str(i),'=str1;']);
    score(1,i)=input('math score:   ');
    score(2,i)=input('english score:   ');
    avg(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
end

% output value
for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the average score of %s is %2.2f \n',str1,avg(i));
end


save score_data N score

clear all;close all;
load score_data