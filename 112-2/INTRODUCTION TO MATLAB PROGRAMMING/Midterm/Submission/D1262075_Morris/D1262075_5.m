R = 0:0.01:10;
L_min = fminbnd(@(L) surfaceArea(R, L),0,100)
L = 0:0.001:100;
R_min = fminbnd(@(L) surfaceArea(R, L),0,10)
min_cost = R_min.*2.*R.*L + L_min.*pi.*R.*R./2
function A = surfaceArea(R, L)
   A = 2.*R.*L+pi.*R.*R./2;
end