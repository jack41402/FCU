%==========================================================================
% sec. 4.1 some common used build-in functions 
% help --> MATLAB  --> mathematics --> elementary function --> 
%==========================================================================
x = -1:.1:1;
figure, plot(x,abs(x),'o')


% atan2(Y,X) is the four quadrant arctangent of the elements
%    of X and Y. -pi <= atan2(Y,X) <= pi.
clear all;
x = [1 -1 -1 1];
y = [1 1 -1 -1];
z=x+1i.*y;
z2=x(2)+1i*y(2);

mag_z2=abs(z2);
ang_z2=atan2(y(2),x(2)) * 180/pi;

x2=mag_z2.*cosd(ang_z2);
y2=mag_z2.*sind(ang_z2);

% in radian
x2=abs(z).*cos(atan2(y,x));
y2=abs(z).*sin(atan2(y,x));

t = clock; % given a variable of current time
fprintf( ' %02.0f:%02.0f:%02.0f\n', t(4), t(5), t(6) );

x=1:2:7;
cumsum(x')

cumsum(1:4)

date

realmax  % largest positive floating number on your computer

realmin

rem(19, 5)


% The following statements convert 40 inches this way:

feet = fix(40/12)
inches = rem(40, 12)
fprintf( ' %d feet %d inches \n', feet,inches );

% Exercise 4.6

%% Some useful matlab functions for the functional evalution
% polynomial function & its integration and differentiation
% please check the ch4_1.pdf

%% minimum values and roots of the function

hy =@(x) x + 2*exp(-x) - 3;
x=-2:0.2:4;
plot(x,hy(x),'--*')
x_min= fminbnd(hy, 0, 4);
x_root=fzero(hy, 0);

hy2=@(x) (0.025.*x.^5-0.0625.*x.^4-0.333.*x.^3+x.^2);
x=-4:0.2:4;
figure;plot(x,hy2(x),'--*')
x_min= fminbnd(hy2, -1, 4);
x2=fzero(hy2,[-4 -1]);

options = optimset('PlotFcns',@optimplotfval);
Lh=@(x) 100./x(1) - x(1)./tan(x(2)) + 2*x(1)./sin(x(2));
x0=[20,1];
x1 = fminsearch (Lh,x0,options);
% notes that x1 is a local minimum


%%  Using hypot

[X,Y] = meshgrid(0:10, 0:10);
dist=hypot(X,Y); % dist=sqrt(x.^2+y.^2)
figure(11);surf(dist)

%
% Script to compare the acos(x), asin(x), and atan(x)
% functions over the range -1 < x < 1. The values are
% converted to angles in degrees. The results are
% compared graphically.
%
% Script prepared by D. T. Valentine - September 2006.
% Comments modified by D.T.V. ........ 2008/2012/2016.
%
% The question raised is: What range of angles, i.e.,
% which of the four quadrents of the circle from 0 to
% 2*pi are the angular outputs of each of the functions?
clc;
% Assign the values of x to be examined:
x = -1:0.001:1;
%
% Compute the arc-functions:
%
y1 = acos(x);
y2 = asin(x);
y3 = atan(x);
%
% Convert the angles from radians to degrees:
%
y1 = 180*y1/pi;
y2 = 180*y2/pi;
y3 = 180*y3/pi;
%
% Plot the results:
%
plot(y1,x,y2,x,y3,x),grid
legend('asin(x)', 'acos(x)', 'atan(x)')
xlabel('\theta in degrees')
ylabel('x, the argument of the function')
% REMARKS: Note the following:
% (1) The acos(x) varies from 0 to 90 to 180 degrees.
% (2) The asin(x) varies from -90 to 0 to 90 degrees.
% (3) The atan(x) varies from -90 to 0 to 90 degrees.
% To check remark (3) try atan(10000000) *180/pi.
%
% Stop


%% Exercise check the formula in EX. 3.7, p.98  and written as Matlab code
% given the parameters

t = 0:0.1:10;% t from0 to 10 in increments of 0.1
k = 1;
R = 0:0.5:2; % R from0 to 2 in increments of 0.5
Ro2 = R./2; %±a¤Jyªº(R/2)
omega0 = sqrt(k); %W0
% write the expression of W1 & y

%% given x=1:0.1:3  y(x)=sin ((x cos x)/(x^2+3x+1)) plot(x,y)


%%==========================================================================
% Sec. 4.2 Import and Export data by load & save commands
% data file have two format: binary & ASCII 
%%==========================================================================


A =[1 2 3
    4 5 6]
save myData A  % Export binary data
clear all;
load myData


save myData.txt A -ascii   % Export ASCII data
B = load('myData.txt')

SS = ['A','B'; 'C', 'D']
save myData.txt SS -ascii
B = load('myData.txt')



%==========================================================================
%==========================================================================




A = [1 2 3; 4 5 6]
B = 3
C = [8 9 8]

save myData A B C

save myData1 A B   % selective save
clear

clear all;
load myData

%==========================================================================
%==========================================================================








