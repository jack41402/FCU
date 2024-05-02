L = 0:0.01:35
R = 0:0.01:30
% L = (2000 - (pi*(R^2)*0.5))./(2*R);
cost = @(R, L) 40.*(2*L + 4*R) + 50*pi*R;
[R_min, L_min] = fminbnd(cost(R, L));
R_min = R_min
L_min = L_min
min_cost = 40.*(2*L_min + 4*R_min) + 50*pi*R_min;