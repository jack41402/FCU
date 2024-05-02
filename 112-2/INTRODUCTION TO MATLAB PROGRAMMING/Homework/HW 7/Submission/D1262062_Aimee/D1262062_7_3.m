x = 1;
hs = [1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5];
fprintf("y =\n\t%.4f", newquot(x, hs))
function deri = newquot(x, hs)
    for i = 1:length(hs)
        h = hs(i);
        deri = (f(x + h) - f(x)) / h;
    end
end
function y = f(x)
    y = x.^3;
end