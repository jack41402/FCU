% 3.7
clear;clc
t = 0:0.1:10;% t from0 to 10 in increments of 0.1
k = 1;
R = 0:0.5:2; %R from0 to 2 in increments of 0.5
Ro2 = R./2; %帶入y的(R/2)
omega0 = sqrt(k); %W0
omega1 = sqrt(omega0.^2 - R.^2./4); %W1
aa=['r', 'g', 'b', 'y', 'cm'];
for iR = 1:length(R)
y = exp(-Ro2(iR).*t).*sin(omega1(iR).*t);%公式
plot(t,y, aa(iR)),hold on %畫圖
end
legend('R=0','R=0.5','R=1','R=1.5','R=2');%標籤