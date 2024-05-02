load('score_data.mat');

for i = 1:N
    avg(i)=(score(1,i)+score(2,i))/2;
end

gpa = [4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.0, 0.0, 0.0];

stu_score = zeros(size(avg));

for i=1:N
    if(avg(i)>=90)
        stu_score(i)=gpa(1);
    elseif(avg(i)>=85)
        stu_score(i)=gpa(2);
    elseif(avg(i)>=80)
        stu_score(i)=gpa(3);
    elseif(avg(i)>=77)
        stu_score(i)=gpa(4);
    elseif(avg(i)>=73)
        stu_score(i)=gpa(5);
    elseif(avg(i)>=70)
        stu_score(i)=gpa(6);
    elseif(avg(i)>=67)
        stu_score(i)=gpa(7);
    elseif(avg(i)>=63)
        stu_score(i)=gpa(8);
    elseif(avg(i)>=60)
        stu_score(i)=gpa(9);
    elseif(avg(i)>=40)
        stu_score(i)=gpa(10);
    elseif(avg(i)>=1)
        stu_score(i)=gpa(11);
    else
        stu_score(i)=gpa(12);
    end
end

for i=1:N
    eval(['str1=name',int2str(i),';']);
 fprintf('the gpa of %s is %3.2f \n',str1,stu_score(i));
end
save score_data_2 N score 