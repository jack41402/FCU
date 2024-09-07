close all;clear all;
time = 0:1:5;
temp = [20,25,27,28,27,25];
[k,i] = fit(time',temp','poly4');
y=k(3.6);
sse = i.sse;
rsqu = i.rsquare;
fprintf("y =\n   %.4f\nSSE: %.6f\nR-suqared: %.4f\n",y,sse,rsqu)
%R-square: It measures how successful the fit is in explaining the variation of the data.
%SSE(Sum of Squares Due to Error): It measures the total deviation of the response values from the fit to the response values.