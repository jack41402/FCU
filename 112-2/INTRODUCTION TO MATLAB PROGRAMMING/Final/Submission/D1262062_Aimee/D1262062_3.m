f1 = figure;
f2 = figure;
a = 4/21;
b = 2/21;
x = -2:a:2;
y = -1:b:1;
[x, y] = meshgrid(x, y);
Z = Zernike(x,y);
surf(x, y, Z);
c = 180/10;
el = 180/12;
for i = -180:c:180
    view(i,el)
end