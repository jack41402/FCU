load score_data % input N score
gpa=zeros(1,N);

for i=1:N
    avg(i)=(score(1,i)+score(2,i))/2; % avg(i) = sum(score(:,i))/2;
    if (avg(i)>=90)
    gpa(i)=4.3;
    elseif(avg(i)>=85)
    gpa(i)=4.0;
    elseif(avg(i)>=80)    
    gpa(i)=3.7;
    elseif(avg(i)>=77)
    gpa(i)=3.3;
    elseif(avg(i)>=73)
    gpa(i)=3.0;
    elseif(avg(i)>=70)
    gpa(i)=2.7;
    elseif(avg(i)>=67)
    gpa(i)=2.3;
    elseif(avg(i)>=63)
    gpa(i)=2.0;
    elseif(avg(i)>=60)
    gpa(i)=1.7;
    elseif(avg(i)>=40)
    gpa(i)=1.0;
    else 
    gpa(i)=0;
    end
end

save score_data2 gpa avg N score