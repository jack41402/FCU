
function [newBalance, rate]= cal_balance(money,num_month,rate)
% input variable : (1) momey : initial balance ; (2) num_month : number of month
% rate : rate per month
% output : newBalance (1,num_month) : Balance of every num_month.

newBalance = zeros(1,num_month);

for k=1:num_month %% 月份
   money = money *(rate+1);%%本金加利息
    newBalance(k)=money;%%每月存款結算
    money=money+50;%%每月定存
end