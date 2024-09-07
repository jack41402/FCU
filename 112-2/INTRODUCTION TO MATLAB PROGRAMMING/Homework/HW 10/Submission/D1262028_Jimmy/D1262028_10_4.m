steps = 0; % iteration counter
x = input( 'Initial guess: '); % estimate of root
re = 1e-8; % required relative error
f = @(x) x^3 + x - 3;
df = @(x) 3*x^2 + 1;
myrel = 1;
for i = 1:20
    xold = x;
    x = x - f(x)/df(x);
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
    if myrel <= re
        break;
    end
end
if myrel <= re
    disp( 'Zero found at' )
    disp( x )
else
    disp( 'Zero NOT found')
end