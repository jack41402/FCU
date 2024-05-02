close all; clear all;

N=input('   number of student:   ');
score=zeros(2,N);

for i=1:N
    str1= input('student name:','s');
    eval(['name',int2str(i),'=str1;']);

score(1,i)=input('math score:   ');
score(2,i)=input('english score:   ');
avg(i)=(score(1,i)+score(2,i))/2;
end

for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the average score of %s is %3.2f \n',str1,avg(i));
end

for i=1:N
    if(avg(i)>=90 & avg(i)<=100) gpa(i) = 4.3
    elseif (avg(i)>=85 & avg(i)<=89) gpa = 4.0 
    elseif (avg(i)>=80 & avg(i)<=84) gpa = 3.7
    elseif (avg(i)>=77 & avg(i)<=79) gpa = 3.3
    elseif (avg(i)>=73 & avg(i)<=76) gpa = 3.0
    elseif (avg(i)>=70 & avg(i)<=72) gpa = 2.7
    elseif (avg(i)>=67 & avg(i)<=69) gpa = 2.3
    elseif (avg(i)>=63 & avg(i)<=66) gpa = 2.0    
    elseif (avg(i)>=60 & avg(i)<=62) gpa = 1.7
    elseif (avg(i)>=40 & avg(i)<=59) gpa = 1.0
    elseif (avg(i)>=1 & avg(i)<=39) gpa = 0
    else gpa = 0
    end
end
save score_data_2 N avg gpa score 

