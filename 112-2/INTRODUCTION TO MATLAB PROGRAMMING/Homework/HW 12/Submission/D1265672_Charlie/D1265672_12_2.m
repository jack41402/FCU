t = [0, 1, 2, 3, 4, 5, 6]; 
T = [300, 150, 75, 35, 12, 5, 2]; 
n=5
p = polyfit(t, T, n);

T_fit = polyval(p, t);

plot(t, T, 'o'); 
hold on;
plot(t, T_fit, '-'); 