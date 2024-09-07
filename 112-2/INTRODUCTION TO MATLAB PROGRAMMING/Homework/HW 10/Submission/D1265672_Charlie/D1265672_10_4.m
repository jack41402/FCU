steps = 0; % iteration counter
x = input('Initial guess: '); % estimate of root
re = 1e-8; % required relative error
myrel = 1; 

f = @(x) x^3 + x - 3; 
df = @(x) 3*x^2 + 1;  

for k = 1:20
    xold = x;
    x = x - f(x) / df(x);
    steps = steps + 1;
    disp([x f(x)]);
    myrel = abs((x - xold) / x);
    
    if myrel <= re
        disp('Zero found at');
        disp(x);
        break; 
    end
end

if myrel > re
    disp('Zero NOT found');
end
