
function [newBalance, rate]= cal_balance(money,num_month,rate)
% input variable : (1) momey : initial balance ; (2) num_month : number of month
% rate : rate per month
% output : newBalance (1,num_month) : Balance of every num_month.

newBalance = zeros(1,num_month);

for k=1:num_month %% ���
   money = money *(rate+1);%%�����[�Q��
    newBalance(k)=money;%%�C��s�ڵ���
    money=money+50;%%�C��w�s
end