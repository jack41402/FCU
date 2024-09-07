clear all;
T = [273 278 283 288 293 298];
P = [4.579 6.543 9.209 12.788 17.535 23.756];
f2 = fit(T', P', 'poly2');

T_285 = f2(285);
T_300 = f2(300);
fprintf('T_285 =\n   %.4f\n', T_285);
fprintf('T_300 =\n   %.4f\n', T_300);

plot(T, P,'.',T,P)
xlabel('x')
ylabel('y')
legend