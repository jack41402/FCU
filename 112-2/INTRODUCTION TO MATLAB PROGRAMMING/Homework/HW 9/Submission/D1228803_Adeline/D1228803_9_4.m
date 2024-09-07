f = @(x) x^3 + x - 3;
df = @(x) 3*x^2 + 1;

x = input('Initial guess: ');
re = 1e-3;
steps = 20;

for i = 1:steps
    xold = x;
    x = x - f(x)/df(x);
    disp([x, f(x)]);
    myrel = abs((x - xold)/x);
    if myrel <= re
        disp('Zero found at');
        disp(x);
        break; 
    end
end

if myrel > re
    disp('Zero NOT found');
end