%   Debugging a script Newton��s method in general: Check the procedure in p. 175 for the debugging  a script Newton??s method in general
% (1) set breakpoint at Line 4; and Line 11% (2) run & continuous to run the program
clear all;clc;
steps = 0; % iteration counter
x = input( 'Initial guess: '); % estimate of root
re = 1e-8; % required relative error
myrel = 1;

while myrel > re & (steps < 20)
    xold = x;
    x = x - f(x)/df(x);
    steps = steps + 1;
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
end
if myrel <= re
    disp( 'Zero found at' )
    disp( x )
else
    disp( 'Zero NOT found')
end