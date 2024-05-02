%L=((2000-(pi*R*R)/2)/(2*R));

cost=@(R) 40*(((2000-(pi*R*R)/2)/(2*R))*2+2*R)+(R*pi)*50;

fprintf("a.\n");

R_min=fminbnd(cost, 0, 100)
L_min=((2000-(pi*R_min*R_min)/2)/(2*R_min))

fprintf("b.\n\n");

min_cost=cost(R_min);
fprintf("min_cost=\n");
fprintf("       %.2f\n", min_cost);

