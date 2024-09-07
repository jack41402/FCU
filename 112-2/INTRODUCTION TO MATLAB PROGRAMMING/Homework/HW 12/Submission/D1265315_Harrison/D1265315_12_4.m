clear all; close all;
t = [273, 278, 283, 288, 293, 298];
p = [4.579, 6.543, 9.209, 12.788, 17.535, 23.756];
f2 = fit(t',p','poly2');
T_285 = f2(285);
T_300 = f2(300);
fprintf("T_285 =\n   %.4f\nT_300 =\n   %.4f\n",T_285,T_300)
plot(t,p,'.',t,f2(t))
xlabel('x');
ylabel('y');
legend('data','fitted curve');