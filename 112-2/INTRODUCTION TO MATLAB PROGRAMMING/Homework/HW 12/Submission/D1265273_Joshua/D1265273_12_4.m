clear all;
t = [273 278 283 288 293 298];
P = [4.579 6.543 9.209 12.788 17.535 23.756];
f = polyfit(t,P,1);
f2 = fit(t', P', 'poly2');
T_285 = f2(285)
T_300 = f2(300)
plot(t, P,'.',t,P)
xlabel('x')
ylabel('y')
legend('data', 'fitted curve');