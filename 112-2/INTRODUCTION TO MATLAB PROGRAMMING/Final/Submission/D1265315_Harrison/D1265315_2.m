x = [0 1 2 3 4 5];
y = [20 25 27 28 27 25];
p = polyfit(x, y, 4);
Y = polyval(p, 3.6);
y_fit = polyval(p, x);
SSE = sum((y - y_fit).^2);
SST = sum((y - mean(y)).^2);
R_square = 1 - (SSE/SST);

Y
SSE
R_square