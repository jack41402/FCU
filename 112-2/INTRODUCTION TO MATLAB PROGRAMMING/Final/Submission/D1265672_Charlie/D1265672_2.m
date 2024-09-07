x = [0, 1, 2, 3, 4, 5];
y = [20, 25, 27, 28, 27, 25];
k=1:4;
r = -inf;
s = 0;
for n = k
    ft = fittype(['poly' num2str(n)]);
    [curve, gof] = fit(x', y', ft);

    if gof.rsquare > r
        r = gof.rsquare;
        s = gof.sse;
    end
end
y=curve(3.6)
fprintf('SSE: %.6f\n', s);
fprintf('R-squared: %.4f\n', r);
%SSE is sum-of-squares error the lower the value is more accurate it is, and 
%the higher the r-square value is the better fit for the data 