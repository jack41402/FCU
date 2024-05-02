R = 1:0.1:30;
L = @(R)-R*pi/4+1000/R;
a = @(R)50*2*R*pi/2+40*2*((-R*pi/4+1000/R)+2*R);
R_min = fminbnd(a,0,30)
L_min = L(R_min)
min_cost = a(R_min)
