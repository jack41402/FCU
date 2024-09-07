f = @(x) x^3 + x - 3; 
df = @(x) 3*x^2 + 1;
x = input('Initial guess: ');
re = 1e-8;
steps = 0;
myrel = 1;
for steps = 1:19
    xold = x;
    x = x - f(x) / df(x);
    fprintf('%10.4f %10.4f\n', x, f(x)); % Right-align with field width 10 and 4 decimal places
    myrel = abs((x - xold) / x);
    if myrel <= re
        break;
    end
end
if myrel <= re
    disp('Zero found at:');
    disp(x);
else
    disp('Zero NOT found within the specified number of iterations.');
end
