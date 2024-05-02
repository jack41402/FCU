A = 2*L*R+pi*R^2;
A = 2000;
cost1 = 50;
cost2 = 40;
fminbnd(A, 0, 2000)
disp(R_min)
disp(L_min)
disp(min_cost)