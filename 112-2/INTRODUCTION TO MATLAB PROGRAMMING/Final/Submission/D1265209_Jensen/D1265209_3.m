[x, y] = meshgrid(-2:4/21:2, -1:2/21:1);
p = @(x,y) (x.^(2)+y.^(2)).^(1./2);
a = @(x,y) atan(y./x)

p_values = p(x, y);
a_values = a(x, y);

result = atan2(p_values, a_values);

mesh(result)
surface(result)
view(180./2, -180:18:180);