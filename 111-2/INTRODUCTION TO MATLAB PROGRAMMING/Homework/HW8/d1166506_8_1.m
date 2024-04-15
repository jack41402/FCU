step = 0 ;
format compact
x = input('Initial guess: ') ;
eps = 1e-8 ;
relative = 1 ;
while (relative>eps && step<20)
    xold = x ;
    x = x - f(x)/df(x) ;
    step = step + 1 ;
    disp([x f(x)])
    relative = abs((x-xold)/x) ;
    if relative<=eps
        break ;
    end
end

if relative<=eps
    disp( 'Zero found at' )
    disp( x )
else
    disp( 'Zero NOT found')
end

function y = f(x)
    y = x^3 + x - 3 ;
end

function y = df(x)
    y = 3*x^2 + 1 ;
end