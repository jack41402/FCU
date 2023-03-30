clear;clc;
N=input('   number of student:   ');
score=zeros(2,N);

% input the name and score of the student evaluate the average score
for i=1:N
    str1= input('student name:','s');
    eval(['name',int2str(i),'=str1;']);
%     if (i==1)
%         name=str1;
%     else
%         name=char(name,str1); % Create a character array.
%     end
score(1,i)=input('math score:   ');
score(2,i)=input('english score:   ');
avg(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
end

% output value
for i=1:N
    eval(['str1=name',int2str(i),';']);
    fprintf('the average score of %s is %3.2f \n',str1,avg(i));
    fprintf("The average GPA of %s is " , str1) ;
    if (avg(i)>=90) fprintf("4.3\n") ;
    elseif (avg(i)>=85) fprintf("4.0.\n") ;
    elseif (avg(i)>=80) fprintf("3.7.\n") ;
    elseif (avg(i)>=77) fprintf("3.3.\n") ;
    elseif (avg(i)>=73) fprintf("3.0.\n") ;
    elseif (avg(i)>=70) fprintf("2.7.\n") ;
    elseif (avg(i)>=67) fprintf("2.3.\n") ;
    elseif (avg(i)>=63) fprintf("2.0.\n") ;
    elseif (avg(i)>=60) fprintf("1.7.\n") ;
    elseif (avg(i)>=40) fprintf("1.0.\n") ;
    elseif (avg(i)>=0) fprintf("0.0.\n") ;
    end
end
