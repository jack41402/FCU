
[x, y] = meshgrid(-2 : 0.2 : 2 , -1 :0.1 : 1);

z = Zernike(x, y);


figure;
surf(x, y, z);

for i = (-180 : (180/10) : 180);

    view([i, 180/12]);

    pause(0.1);
end

figure;
mesh(x, y, z);