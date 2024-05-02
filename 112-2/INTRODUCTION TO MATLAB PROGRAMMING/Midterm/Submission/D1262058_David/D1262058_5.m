fprintf("a.\n");
y = @(R) (2*R + (2000-0.5*pi*R^2)/(2*R) + (2000-0.5*pi*R^2)/(2*R))*40 + pi*R*50;
R_min = fminbnd(y, 0, 25)
L_min = (2000-0.5*pi*R_min^2)/(2*R_min)
fprintf("b.\n");
min_cost = y(R_min);
fprintf("min_cost = \n%.2f", min_cost)