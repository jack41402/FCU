

A = 2000; 
cost_curved = 50;
cost_straight = 40; 
L = (A -pi.*R.^2)./2.*R;
cost = @(R) 50*pi.*R + 40*(2.*R + 2.*L);

R_min = fminbnd(cost,1,100);

L_min = (A - pi.*R_min.^2)/(2.*R_min);
L = L_min;

C_min = cost(R_min);

fprintf('The optimal values are R = %.2f ft and L = %.2f ft.\n', R_min, L_min);
fprintf('The minimum cost is $%.2f.\n', C_min);