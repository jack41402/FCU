T = [273, 278, 283, 288, 293, 298]';
P = [4.579, 6.543, 9.209, 12.788, 17.535, 23.756]';
X = 1 ./ T; 
Y = log(P);
coe = polyfit(X,Y,2);
fuction = @(x) exp(polyval(coe,1./x));
T_range = linspace(min(T), max(T), 100);
P_fit = fuction(T_range);
figure;
hold on;
plot(T, P, 's', 'MarkerEdgeColor', 'b', 'MarkerFaceColor', 'b'); 
plot(T, P, 'r-'); 
xlim([270 300]);
ylim([4 24]);
xlabel('x');
ylabel('y');
legend('Data', 'Fitted curve');
T_285 = 284.9533;
T_300 = 299.7083;
P_285 = fuction(T_285);
P_300 = fuction(T_300);
fprintf('T_285:\n %.4f \n', P_285);
fprintf('T_300:\n %.4f \n', P_300);