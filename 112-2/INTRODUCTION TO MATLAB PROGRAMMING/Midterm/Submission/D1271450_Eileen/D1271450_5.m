A=2000;
c=50;
s=40;
(2*R*L+pi*R^2)==2000
s=@(R,L)(2*R+L)*s+(2*R*pi)*c
[R_min,L_min] = fminbnd(s,0,0.01)
x=(2*R*L)*s+(pi*R^2)*c;
fprintf("min_cost=%.2f",x)
