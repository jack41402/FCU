x = input('initial guess: ');
f = @(x) x.^3 + x - 3;
df = @(x) x.^2.*3 + 1;
error = 1e-8;
myerror = 1;
for i = 1:10
    xold = x;
    x = x - f(x)/df(x);
    myerror = abs(xold-x);
    if(myerror<error)
        break
    end
    disp([x f(x)])
end
fprintf("Zeor found at\n");
disp(x);
