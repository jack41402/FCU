y = @(x) x.^3
x = 1;
hs = [1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5];
for i = 1:length(hs)
    h = hs(i);
    deri = (f(x + h) - f(x)) / h;
    fprintf("y =\n\t%.4f\n", deri)
end