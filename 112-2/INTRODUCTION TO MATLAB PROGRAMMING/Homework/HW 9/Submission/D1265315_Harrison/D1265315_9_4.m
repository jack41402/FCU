x = input( 'Initial guess: ');
f = @(a) a.^3+a-3;
df = @(b) 3.*b.^2+1;
re = 1e-8; 
myrel = 1;
flag = 0;
for i = 1:20
    xold = x;
    x = x - f(x)/df(x);
    disp( [x f(x)] )
    myrel = abs((x-xold)/x);
    if myrel <= re
        disp( 'Zero found at' )
        disp( x )
        flag = 1;
        break
    end
end

if(flag~=1)
    disp('Zero not found')
end
