steps = 0;
x = input( 'Initial guess: ' );
re = 1e-8;
myrel = 1;

while myrel > re & (steps < 20)
    xold = x;
    %f(x)
    %df(x)
    x = x - f(x)/df(x); 
    steps = steps +1;
    x
    f(x)
    disp( [x f(x)] )
    
    myrel = abs((x-xold)/x);
end

if myrel <= re
    disp( 'Zero found at' )
    disp( x )
else
    disp( "Zero NOT found" )
end