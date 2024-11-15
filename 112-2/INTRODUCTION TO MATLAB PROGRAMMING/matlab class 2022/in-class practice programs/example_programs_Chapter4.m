%%  Using hypot

[X,Y] = meshgrid(0:10, 0:10);
dist=hypot(X,Y);

%==========================================================================
%==========================================================================
x = -1:.1:1;
figure, plot(x,abs(x),'o')


clear all;
x = [1 -1 -1 1];
y = [1 1 -1 -1];
atan2(y,x) * 180/pi
atan(y./x) * 180/pi

x=-1;
y=-1;
atan2(y,x) * 180/pi
atan(y./x) * 180/pi

t = clock;
fprintf( ' %02.0f:%02.0f:%02.0f\n', t(4), t(5), t(6) );

cumsum(1:4)

date

realmax

realmin

rem(19, 5)


% The following statements convert 40 inches this way:

feet = fix(40/12)
inches = rem(40, 12)

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

%
% REMARKS: Note the following:
% (1) The acos(x) varies from 0 to 90 to 180 degrees.
% (2) The asin(x) varies from -90 to 0 to 90 degrees.
% (3) The atan(x) varies from -90 to 0 to 90 degrees.
% To check remark (3) try atan(10000000) *180/pi.
%
% Stop

%%==========================================================================
% Sec. 4.2 Import and Export data by load & save commands
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

clear

load myData





%==========================================================================
%==========================================================================








