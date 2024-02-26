%% prog. 1.1 -1
clear all;close all;
A=magic(3);
B=floor(5*rand(3,4));
C=A*B;
D=inv(A);
whos
clc
clear

%% prog. 1.1 -2      vector,   help plot & plot function & figure properties
% on the plot

x = -pi:pi/10:pi; % provide more detail for the vector 
xs=size(x);

       y = sin(x);
       plot(x,y,'--rs','LineWidth',2,...
                       'MarkerEdgeColor','k',...
                       'MarkerFaceColor','g',...
                       'MarkerSize',5)
xlabel('x-value','Color','r','fontsize',20);ylabel('sinx');
axis([-3.5 3.5 -1.2 1.2]);
% title(...,'PropertyName',PropertyValue,...)
title('my first plot','Color','r','fontsize',20); 
% the property can also be used for xlabel & ylabel

% add text anywhere in your plot
figure; % generate an new figure
plot(0:pi/20:2*pi,sin(0:pi/20:2*pi))
text(pi,0,' \leftarrow sin(\pi)','FontSize',18)
% then you can move your text by toolbox in the figure %Tools %Edit plot

%% prog 1.1 -3  % linear equation p. 11

% matrix method
AA=[ 1 2; 2 -1];
BB=[ 4; 3];
x1=AA\BB;

%% prog 1.2
clear all;close all;
X=0:1:5000;
% the mu and sigma are the function of the mean and variance of the lognormal 
m = 444.84;
v = 2042.56^2;
mu = log((m^2)/sqrt(v+m^2));
sigma = sqrt(log(v/(m^2)+1));
disp([mu sigma]);
% Y = lognpdf(X,mu,sigma)
Y = lognpdf(X,mu,sigma);
figure(1);semilogx(X+1,Y,'--*g')
xlabel('log(1+X)');ylabel('normalized density');
figure(2);loglog(X,Y,'--*g')


%%  prog 1.3-1 

bal = 1000;
rate=0.1;
inter=rate * bal;
newbal = bal + inter;
disp( 'New balance is:' )
disp( newbal )



% build-in function method
[x ,y]=solve('x+2*y=4','2*x-y=3');






                   
