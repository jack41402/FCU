format compact
f = @(x) x.^3 + x - 3;
df = @(x) 3.*x.^2 + 1;
x = input("Initial guess: ");
epsilon = 1e-8;

for step=1:20
    xold = x;
    x = x - f(x)/df(x);
    disp([x f(x)])
    if (abs((x-xold)/x)<=epsilon)
        disp('Zero found at')
        disp(x)
        break
    end
end

if (abs((x-xold)/x)>epsilon)
    disp('Zero NOT found')
end