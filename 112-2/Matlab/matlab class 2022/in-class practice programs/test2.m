clear all;clc;
steps = 0; % iteration counter
x = 2; %input( 'Initial guess: '); % estimate of root
re = 1e-8; % required relative error
myrel = 1;i=1;
while myrel > re & (steps < 20)
    xold = x;
    x = x - f(x)/df(x);
    steps = steps + 1;
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
    disp(i);
    i=i+1;
end
if myrel <= re
    disp( 'Zero found at' )
    disp( x )
else
    disp( 'Zero NOT found')
end
x=0:0.1:3;
figure(1);plot(x,f(x))
