steps = 0;
x = input('Initial guess: ');
re = 1e-8;
myrel = 1;
max_steps=20;

f = @(x) x^3 + x - 3;
df = @(x) 3*(x^2) + 1;

for steps = 1:max_steps
    xold = x; 
    x = x - f(x)/df(x); 
    myrel = abs((x - xold)/x); 

    disp([x f(x)])

    if myrel <= re
        disp('Zero found at')
        disp(x)
        break;
    end
end

if myrel > re
    disp('Zero NOT found')
end
