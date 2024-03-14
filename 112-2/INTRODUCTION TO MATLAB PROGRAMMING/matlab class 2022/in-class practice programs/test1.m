% excludes zero roots!

steps = 0; % iteration counter
x = input( 'Initial guess: '); % estimate of root
re = 1e-8; % required relative error
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

fh1=@(x) exp((-0.2).*x).*sin(x+2)
X = fminbnd(fh1,0,10)

fh2 = @(x,c) (x-c).^2; % the value of the parameter is not defined yet
c = 1.5; 
fh3 = @ (x) fh2(x,c);  % Now the value is defined 
d=fh3(3)





