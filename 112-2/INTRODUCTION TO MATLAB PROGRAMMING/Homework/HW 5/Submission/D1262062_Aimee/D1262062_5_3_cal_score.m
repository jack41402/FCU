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

for i=1:N
    if(avg(i)>=90)
        gpa(i) = 4.3;
    elseif(avg(i)<90 & avg(i)>=85)
            gpa(i) = 4.0;
    elseif(avg(i)<85 & avg(i)>=80)
            gpa(i) = 3.7;
    elseif(avg(i)<80 & avg(i)>=77)
            gpa(i) = 3.3;
    elseif(avg(i)<77 & avg(i)>=73)
            gpa(i) = 3.0;
    elseif(avg(i)<73 & avg(i)>=70)
            gpa(i) = 2.7;
    elseif(avg(i)<70 & avg(i)>=67)
            gpa(i) = 2.3;
    elseif(avg(i)<67 & avg(i)>=63)
            gpa(i) = 2.0;
    elseif(avg(i)<63 & avg(i)>=60)
            gpa(i) = 1.7;
    elseif(avg(i)<60 & avg(i)>=40)
            gpa(i) = 1.0;
    elseif(avg(i)<40)
            gpa(i) = 0;
    end
end

save score_data2 N avg gpa score 