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

avg(i) = mean(score(:,i));
end

for i=1:N
stdd(i) = std(score(i,:));
maxx(i) = max(score(i,:));
minn(i) = min(score(i,:));
end

str3 = ["math", "english"];
% output value
for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the average score of %s is %3.2f \n',str1,avg(i));
end

for i=1:N
 fprintf('the standard deviation of %s is %3.2f \n',str3(i),stdd(i));
end

for i=1:N
 fprintf('the maximum of %s is %3.2f \n',str3(i),maxx(i));
end

for i=1:N
 fprintf('the minimum of %s is %3.2f \n',str3(i),minn(i));
end

save score_data N score 