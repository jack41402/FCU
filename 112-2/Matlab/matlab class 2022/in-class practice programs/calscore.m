function [s_max,s_min,s_avg]=calscore(N,score)
class_num=length(score(1,:));
s_max=zeros(1,class_num);
s_min=zeros(1,class_num);
s_avg=zeros(1,class_num);
for i=1:class_num
    s_max(i)=max(score(:,i));
    s_min(i)=min(score(:,i));
    s_sum=sum(score(:,i));
    s_avg(i)=s_sum/N;
end
end

    
