re = 1e-8; 
x = input('Initial guess: ');
for steps = 1:20
    xold = x;
    x = x - f(x) / df(x);
    disp([x, f(x)])
    myrel = abs((x - xold) / x);
    if myrel <= re
        disp('Zero found at')
        disp(x)
        break;
    end
end

if myrel > re
    disp('Zero NOT found')
end

function y = f(x)
    y =x.^3+x-3;
end

function dy = df(x)
    dy = 3.*x.^2+1;
end