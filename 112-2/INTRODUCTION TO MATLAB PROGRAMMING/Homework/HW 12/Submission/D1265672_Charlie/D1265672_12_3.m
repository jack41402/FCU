t = 0:0.5:4; 
V = [100, 62, 38, 21, 13, 7, 4, 2, 3]; 
n=8
p = polyfit(t, V, n);

V_fit = polyval(p, t);

plot(t, V, 'o'); 
hold on;
plot(t, V_fit, '-'); 