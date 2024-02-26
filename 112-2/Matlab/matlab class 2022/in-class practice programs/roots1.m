function [x]=roots1(f,df,x0)
steps = 0; % iteration counter

re = 1e-8; % required relative error
myrel = 1;
x = x0;  % estimate o
for steps=1:19
    xold = x;
    x = x - f(x)/df(x);
    steps = steps + 1;
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
    if myrel <= re
         break;
    end
end