
T = [0, 1, 2, 3, 4, 5]';
P = [20, 25, 27, 28, 27, 25]';
X = 1 ./ T; 
Y = log(P);
coe = polyfit(X,Y,2);
fuction = @(x) exp(polyval(coe,1./x));
T_range = linspace(min(T), max(T), 100);
P_fit = fuction(T_range);

T_285 = 200;

P_285 = fuction(T_285);

fprintf('T_285:\n %.4f \n', P_285);









