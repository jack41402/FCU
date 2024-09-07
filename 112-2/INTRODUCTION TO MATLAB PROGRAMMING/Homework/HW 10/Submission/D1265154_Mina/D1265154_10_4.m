f = @(x)x^3 + x - 3;
df = @(x)3*x^2+1;
steps = 0; 
x = input( 'Initial guess: ');
re = 1e-8; 
myrel = 1;
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
if myrel <= re
    disp( 'Zero found at' )
    disp( x )
else
    disp( 'Zero NOT found')
end
