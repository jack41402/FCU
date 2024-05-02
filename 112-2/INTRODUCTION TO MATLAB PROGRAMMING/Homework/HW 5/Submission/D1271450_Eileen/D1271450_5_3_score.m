close all; clear all;


N=input('   number of student:   ');
score=zeros(2,N);


for i=1:N
    str1= input('student name:','s');
    eval(['name',int2str(i),'=str1;']);

score(1,i)=input('math score:   ');
score(2,i)=input('english score:   ');

end



save score_data N score 