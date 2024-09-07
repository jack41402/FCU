Time = 0:5;
Temp = [20, 25, 27, 28, 27, 25];
p = polyfit(Time, Temp, 4);
Time_fit = linspace(0, 4);
V_fit = polyval(p, Time_fit);
y = polyval(p, 3.6);
sse = fittype(p)
r_squared = fit(p)
fprintf("SSE: %.6f",sse)
fprintf("\nR-squared: %.4f",r_squared)