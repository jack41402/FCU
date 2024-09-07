f = @(x) x.^3 + 2*x.^2 + 5*x - 4;
x = -5:0.1:5;
h = 1e-3;
df = zeros(size(x));
for i = 1:length(x)
    df(i) = (f(x(i) + h) - f(x(i))) / h;
end
disp('y = ');
disp([df]);
