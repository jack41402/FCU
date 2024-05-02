A = 2000;
R = 0:0.01:50;
L = @(R) (A-(R.^2).*pi)./(2.*R);

R_min = fminbnd(L, 0.01, 100)
L_min = min(L)
min_cost = R_min.*50 + L_min.*40
