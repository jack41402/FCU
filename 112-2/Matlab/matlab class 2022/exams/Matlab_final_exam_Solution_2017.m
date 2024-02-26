
clc;close all;clear; 

% 1

A = [0, -1, 4; 9, -14, 25; -34, 49, 64]
C=A>=0
B = sqrt(A).*(A>=0) + (A+50).*(A<0)   %  Answer

% 2

height = [63, 67, 65, 72, 69, 78, 75]
accept = find(height >= 66)
display ('The following candidates meet the height requirement');
fprintf('Candidate # %4.0f is %4.0f inches tall \n', [accept;  height(accept)])   %  Answer


% 3

t = 0:0.1:100;
height = 2.13* t.^2 - 0.0013* t.^4 + 0.000034 * t.^4.751;
hindex = find(height >= 0)
tindex = t(hindex)
twarning = tindex(length(tindex)) - 2  % answer (a) 61
[Hmax Hmaxindex] = max(height)   % answer (b) Hmax=1470.2
tmax = tindex(Hmaxindex)  % answer (b)  tmax=40.5
figure, plot(tindex, height(hindex))    % answer (c) 
xlabel('time'); ylabel('height'); title('Rocket Trajectory');


% 4

price = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29]

Amount_Buy = sum(((price < 20) * 100 .* price))  % answer(a) = 7300
Amount_received = sum((((price > 25) * 100 .* price))) % answer(b) = 5600
Shares = 1000 + sum((price < 20) * 100) - sum((price > 25) * 100) % answer(c) = 1200
netIncrease = Amount_received - Amount_Buy  %answer(d) = -1700


% 5

L = 50000
p = [850 1000 1200]
r = [0.1 : 0.01 : 0.2]'
r1 = r * 100;
p = repmat(p, [11 1])
r = repmat(r, [1,3])

N = log(p./(p-r.*L/12)) ./ (12*log(1+r/12));

display('  rate %       $850      $1000      $1200')
display([r1, N])



% 6

x = [-2, 0, 2, 4]
y = [-20, 4, 68, 508]'
A = [x.^3; x.^2; x.^1; ones(1,4)]'
P = A\y     % answer: a= 7, b= 5, c= -6, and d= 4




% 7

% (a)
% Type the following command in the command window   
newquot(2) %  Answer: 15

% Function file f.m
function y=f(x)
y=x^3+3*x+8;

% Function file newquot.m
function newquot(x)
h = 1;
for i = 1 : 10
    df = (f(x + h/2) - f(x-h/2)) / h;
    disp( [h, df] );
    h = h / 10;
end

% (b)
%Type the following three statements in the command window
fn = @f;
x = 2;
newquotonquot(fn,x)  %  Answer: 15
% another example
fn = @sqrt; % sine function
x=0.1;
newquotonquot(fn,x)   %  Answer: 1.5811

% Function file newquot_handel.m
function newquotonquot(fn,x)
h = 1;
for i = 1 : 10
    df = (feval(fn, x + h/2) - feval(fn, x-h/2)) / h;
    disp( [h, df] );
    h = h / 10;
end



% 8
amount = 500;
k = 0;
while amount < 10000
k = k + 1;
amount = amount * 1.05 + 500;
end
format bank
display([k, amount])     %  Answer: 14 years ($10789.28)


% 9


x = 0:pi/100:2*pi;
y1 = 2*cos(x);
y2 = cos(x);
y3 = 0.5*cos(x);
figure, plot(x,y1, '--r', x,y2, '-g', x,y3,':b');
xlabel(' x (0:2\pi)');
ylabel('Cosine functions');
legend('2*cos(x)', 'cos(x)', '0.5*cos(x)');
title('Example of three plots');
axis([0 2*pi -3 3]);





% 10

[x y] = meshgrid(-2:0.05:2);
z = exp(-x.^2-y.^2) .* sin(x).*sin(y);
figure, subplot(2,2,1);
mesh(z); title('Mesh surface');
subplot(2,2,2); surf(z); title('Facet surface');
subplot(2,2,3); contour(z); title('Contours');
subplot(2,2,4); meshc(z); title('Mesh surface and contours');




























