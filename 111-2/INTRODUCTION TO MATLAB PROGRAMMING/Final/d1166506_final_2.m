z = @(x , y) x.*exp(-((x-y.^2).^2 + y.^2)) ;

% (a)
[x , y] = meshgrid(-2:4/20:2 , -1:2/20:1) ;

% (b)
mesh(z(x , y)) ;

% (c)
figure
el = 45 ; % pi/4
for az=-pi:pi/10:pi 
    mesh(z(x , y)) , view(az , el)
    pause(0.5)
end

% (d)
figure
V = z(x , y) ;
[dx , dy] = gradient(V , 0.2 , 0.2) ;
contour(x , y , V)
hold on
quiver(x , y , dx , dy)
hold on
colorbar
hold off

% (e)
% Gradient field is a field to see the maximum change of a function at
% arbitrary points.