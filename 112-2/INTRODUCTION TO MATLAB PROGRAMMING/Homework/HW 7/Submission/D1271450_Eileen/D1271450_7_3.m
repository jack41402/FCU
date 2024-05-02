function D1271450_7_3()
function derivative = newquot_fun(f, x, hs)
    for i = 1:length(hs)
        h = hs(i);
        derivative = (f(x + h) - f(x)) / h;
        fprintf('h = %.5f, derivative = %.4f\n', h, derivative);
    end
end
f = @(x) x.^3;
x = 1;
hs = [1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5];

newquot_fun(f, x, hs);
end
