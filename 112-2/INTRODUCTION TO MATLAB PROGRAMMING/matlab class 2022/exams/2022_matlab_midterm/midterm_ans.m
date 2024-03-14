clear;close all;clc;
%% 第一題
A = [6  5   7    pi;
    -9  4  13   exp(2);
     0  3 3*pi  -6;
    13  2   4    8;
sqrt(3) 5   6  log(6)];
B = magic(5);
C = A'*B-200;
%a
D = C';
%b
E = A([2 4],:);
%c
F_plate = ones(6, 5);
F_plate([1 2 4 5 6],:)=B;
F = F_plate;
%d
G=sum(sum(C));
%e
H = F*C'*E';

%% 第二題
clear;clc;
global a
a=2;
par =@(n) a.^n./factorial(n+1);

b = 0:20;

Xn =amonyous(b);
Xn1 =par(b);

fprintf('n    Xn \n')
for i = 1 : 21
    fprintf('%2d    ',i-1);
    fprintf('%1.4e \n',Xn1(i));
end
%% 第三題
clear;clc;
money = 4000;
years=20;
for i = 1:20
    fprintf(['No.',num2str(i),' year ']);
    if (0<=money && money<=5000)
        new_money = money*(1+0.05);
        disp(['the interest rate: 5% , the amount of interest: ',num2str(money*0.05),', the new balance: ',num2str(new_money)]);
    elseif(5000<money && money<=8000)
        new_money = money*(1+0.08);
        disp(['the interest rate: 8% , the amount of interest: ',num2str(money*0.08),', the new balance: ',num2str(new_money)]);
    elseif(8000<=money && money<=10000)
        new_money = money*(1+0.12);
        disp(['the interest rate: 12%, the amount of interest: ',num2str(money*0.12),', the new balance: ',num2str(new_money)]);
    else
        new_money = money*(1+0.15);
        disp(['the interest rate: 15%, the amount of interest: ',num2str(money*0.15),', the new balance: ',num2str(new_money)]);
    end
        money = new_money;
end

%% 第四題
clear;clc;
theta = -pi/4:pi/20:pi/4;
t=0:0.2:2;
a1=5;

%a
theta_1 = repmat(theta',1,size(t,2));
t_1 = repmat(t,size(t,2),1);
a_ans = (exp(2.*t_1).*sin(3.*theta_1)+log(t_1+1)).*cos(theta_1).^2;
%b
b_ans = (asin(a1.*t_1)+log(t_1.^2+t_1+1)).*tan(theta_1);
%c
x = -2*pi:0.01:2*pi;
Fc = 3.*x.*cos(x).^2.*x-2.*x;
plot(x,Fc);
%d
x1 = -2:0.01:16;
Fd = 4*cos(x1)./x1+exp(-0.75*x1);
plot(x1,Fd);

%% 第五題
clear;clc;

Cost = [7 3 2;
        3 1 3;
        9 4 5;
        2 5 4;
        6 2 1];
    
quarterly_production_volume =   [16 14 10 12;
                                 12 15 11 13;
                                 8  9  7 11;
                                 14 13 15 17;
                                 13 16 12 18];
%a
cost_of_each_quarterly = Cost'*quarterly_production_volume;
%b
total_cost_of_each_year = sum(cost_of_each_quarterly');
%c
total_cost_of_each_quarterly = sum(cost_of_each_quarterly);

%% 第六題 
clear;clc;
height =@(V,r) (V-2*pi*r.^3/3)./(pi*r.^2);
tower=@(r) 800*pi*r.*height(600,r)+1200*pi*r.^2;

%a
optimum_r = fminbnd(tower,0,100);
%b
min_cost = tower(optimum_r);
%c
optimum_h =  height(500,optimum_r);


