
t = [0, 1, 2, 3, 4, 5];
y = [20, 25, 27, 28, 27, 25];

a = -inf;
b = 0;

for n = 1:4

    r = fittype(['poly' num2str(n)]);

    [curve, w] = fit(t', y', r);

    if w.rsquare > a

        a = w.rsquare;

        b = w.sse;

    end
end

y = curve(3.6)

fprintf('SSE: %.6f\n', b);

fprintf('R-squared: %.4f\n', a);