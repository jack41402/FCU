x = input( 'Initial guess: '); % estimate of root
re = 1e-8; % required relative error
myrel = 1;
f = @(x) x.^3 + x - 3;
df = @(x) 3.*x.^2 + 1;
for step = 1:1:20
    xold = x;
    x = x - f(x)./df(x);
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
    if(myrel <= re)
        break;
    end
end
if myrel <= re
 disp( 'Zero found at' )
 disp( x )
else
 disp( 'Zero NOT found')
end