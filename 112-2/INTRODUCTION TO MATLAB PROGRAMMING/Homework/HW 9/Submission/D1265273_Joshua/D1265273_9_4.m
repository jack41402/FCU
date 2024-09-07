x = input('Initial guess: ');
f= @(a) a^3+a-3;
df= @(b) 3*b^2+1;
re = 1e-8;
for step=1:20
    xold = x;
    x = x- f(x)/df(x);
    disp([x, f(x)])
    if abs((x-xold)/x)<=re
        break
    end
end
if abs((x-xold)/x)<=re
    disp('zero found at')
    disp(x)
else
    disp('zero not found')
end