[x, y] = meshgrid(-2:0.2:2, -1:0.1:1);
z = Zernike(x, y);
ele = 180/12;
an = -180:(180/10):180;
figure;
surf(x, y, z);
for az = an
    view([az, ele]);
    pause(0.5); 
end
figure;
mesh(x, y, z);