 % input the number of the student
clear all;close all;
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

N=30;
score(1,:)=floor(rand(1,N)*100)+1;
score(2,:)=floor(rand(1,N)*100)+1;
score(3,:)=floor(rand(1,N)*100)+1;
save score_data N score

%% write a sub-function to calculate the max value min value and mean value
% of the ccouse

clc;clear all;
load score_data

k=length(score(:,1)); % how many course
for i=1:k
    smax(i)=max(score(i,:));
    smin(i)=min(score(i,:));
    smean(i)=mean(score(i,:));
end

disp([smax' smin' smean'])



% output value
for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the average score of %s is %3.2f \n',str1,avg(i));
end
save score_data N score