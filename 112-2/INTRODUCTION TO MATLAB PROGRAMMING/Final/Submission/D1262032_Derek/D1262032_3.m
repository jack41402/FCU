[x, y] = meshgrid(-2:0.2:2, -1:0.1:1);
z = Zernike(x, y);
figure;
surf(x, y, z);
elevation = 180/12;
azimuth_angles = -180:(180/10):180;
for azimuth = azimuth_angles
    view([azimuth, elevation]);
    pause(0.5); 
end
figure;
mesh(x, y, z);


