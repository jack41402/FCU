function [smax,smin,smean] = cal_score(N,score)
k=length(score(:,1)); % how many course
for i=1:k
    smax(i)=max(score(i,:));
    smin(i)=min(score(i,:));
    smean(i)=mean(score(i,:));
end

clear all;
load('score_data.mat')
[m n]=size(score);
avg=inline('(x+y)/2','x','y');
for i=1:n
    average(i)=avg(score(1,i),score(2,i));
end

