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
