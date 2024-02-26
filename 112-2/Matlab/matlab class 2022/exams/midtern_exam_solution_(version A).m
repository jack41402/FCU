
% Solution for Version A


y(x)=cos?((x cos?x)/(x^2+3x+1))
x=1:.2:3; theta=pi/4;
y=x.*(sin(theta))./(x.^2+x+1);
plot(x,y)


% 1
clc;clear;close all
x = -2; y = 5; z = 3;

% 1(a)
f = y^(1/3)-x/(y+(x+y)/(x*z))

% 1(b)
f = tand(30) / (tan(pi/4) + cos(pi/3))

% 1(c)
f = exp(log(4))

% 1(d)
f = abs(x)*sin(x^2)

% 1(e)
6*pi*atan(12.5)+4

% 2
clc;clear;close all
% 2(a)
x = -7-5i; y = 4 - 3i;
mf = abs(x*y)
af = angle(x*y)
afd = angle(x*y)*180/pi

% 2(b)
x = -7-5i; y = 4 - 3i;
mf = abs(x/y)
af = angle(x/y)
afd = angle(x/y)*180/pi

% 3
clc;clear;close all
x = -9:3:12
y = sin(x)
% 3(a)
f = x.*y

% 3(b)
f = rem(x,2)

% 4
clc;clear;close all
B = [ 1.5, 1, 3; 6.5, -1.2, 12.4; 2.5, -1, 3.8; 2.4, 8.1, 5.8]

% 4(a) row max
max(B(1,:))
max(B(2,:))
max(B(3,:))
max(B(4,:))

% column max
max(B(:,1))
max(B(:,2))
max(B(:,3))

% 4(b)

min(B(:))


% 5


% 5(a)

clc;clear;close all

tic
sign = -1;
s = 0;

for n = 1:2:2000
    sign = -sign;
    s =s + sign / n;
end
toc
display(s)


% 5(b)

clc;clear;close all

tic
n = 1:4:1998;
s =sum(1./n - 1./(n+2));
toc
display(s);

% 5(c)
% The for loop method:         0.004637 seconds.
% The array operations method: 0.002577 seconds.






% 6
clc;clear;close all

x = 1:0.01:3;
y = sin(x.*cos(x)./(x.^2+3*x+1));
figure, plot(x,y);


% 7
clc;clear;close all

x = linspace(-4,4);
N = length(x)
for  j = 1:N
    if x(j) >=0 & x(j)<=1
        f(j) =x(j);
    elseif x(j)>1 & x(j)<2
        f(j) = 2 - x(j);
    else
        f(j) = 0;
    end
end
    figure, plot(x,f)
    
  
         
% 8 (Ex. 2.25)
clc;clear;close all


balance=6000;%%本金
interest_rate = zeros(1,20);
interest = zeros(1,20);
newBalance = zeros(1,20);

for k=1:20 %% 年份
    %%%利息計算法
    if balance<=5000
        interest_rate(k)=0.05;
        interest(k) = balance * interest_rate(k);
        balance = balance + interest(k);
            
    elseif   balance>10000
        interest_rate(k)=0.1;
        interest(k) = balance * interest_rate(k);
        balance = balance + interest(k);
               
    else     
        interest_rate(k)=0.08;
        interest(k) = balance * interest_rate(k);
        balance = balance + interest(k);
           
    end
    
         newBalance(k)=balance;%%每月存款結算
end

display(['Year' '     Interest Rate' '     Interest ' '      New Balance']);
display(num2str([ (1:20)' interest_rate' interest' newBalance' ]));





% 9
clc;clear;close all

f = input('Enter length in feet: ');
cm = f * 30.48;
m = fix(cm / 100);
cm = rem(cm, 100);
km = fix(m / 1000);
m = rem(m, 1000);
disp( [km m cm] );


% 10 (Ex. 3.5)

clc;clear;close all

[x1,x2]=quadratic(3,3,3);%%呼叫副函式   x1, x2 are complex roots 
                         % x1 x2  -0.5000 + 0.8660i  -0.5000 - 0.8660i

[x1,x2]=quadratic(2,8,8);%%呼叫副函式   equal roots  
                                       % x1 x2    -2    -2
                                       
[x1,x2]=quadratic(9,6,-3);%%呼叫副函式  x1 x2    0.3333   -1.0000




function [x1,x2] = quadratic(a,b,c) %%副程式
% Equation:
% a*x^2 + b*x + c = 0
% Input: a,b,c
% Output: x = [x1 x2], the two solutions of
% this eequation.
if a==0 & b==0 & c==0     %%避免判斷是出錯
    disp(' ')
    disp('Solution indeterminate')
    x1 = NaN;
    x2 = NaN;
elseif a==0 & b==0              %%避免判斷是出錯
    disp(' ')
    disp('There is no solution')
    x1 = NaN;
    x2 = NaN;
elseif a==0                                %%只有單一解
    disp('Only one root: equation is linear')
    disp(' x ')
    x1 = -c/b;
    x2 = NaN;
elseif b^2 < 4*a*c                    %% 解為虛數             
    disp(' x1, x2 are complex roots ')
    disp('x1 x2')
    x1 = (-b + sqrt(b^2 - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b^2 - 4*a*c))/(2*a);
elseif b^2 == 4*a*c                 %%相同解
    x1 = -b/(2*a);
    x2 = x1;
    disp('equal roots')
    disp('x1 x2')
else
    x1 = (-b + sqrt(b^2 - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b^2 - 4*a*c))/(2*a);
    disp('x1 x2')
end
if a==0 & b==0 & c==0
elseif a==0 & b==0
else
    disp([x1 x2]);
end


%將以上副程式部分存檔,檔名為quadratic，可用於下次呼叫
