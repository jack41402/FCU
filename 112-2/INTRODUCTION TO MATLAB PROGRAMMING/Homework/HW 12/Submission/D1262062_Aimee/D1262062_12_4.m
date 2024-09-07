T = 273:5:298;
P = [4.579, 6.543, 9.209, 12.788, 17.535, 23.756];

p = polyfit(T, P, 2);
T_fit = linspace(270, 300);
V_fit = polyval(p, T_fit);
figure;
plot(T, P, '.', 'MarkerSize', 8);
hold on;
plot(T, P);
hold off;
legend('data','fitted curve')

T_285 = polyval(p, 285);
T_300 = polyval(p, 300);
fprintf("T_285 =\n   %.4f", T_285)
fprintf("\nT_300 =\n   %.4f", T_300)