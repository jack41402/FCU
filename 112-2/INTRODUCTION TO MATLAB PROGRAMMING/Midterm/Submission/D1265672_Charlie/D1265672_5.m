r_min = 1;
r_max = 50;

[r, cost] = fminbnd(@cal, r_min, r_max);
l = (2000 - 0.5 * pi * r^2) / (2 * r);

fprintf("R_min = \n   %.4f", r);
fprintf("\nL_min = \n   %.4f", l);
fprintf("\nmin_cost = \n       %.2f\n", cost);
function c = cal(R)
    a = 2000;  
    L = (a - 0.5 * pi * R^2) / (2 * R);
    c = 40 * (2 * L + 2 * R) + 50 * (pi * R);
end