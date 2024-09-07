function z = zernike(x, y)
    angle = atan2(y,x);
    p = (x.*x + y.*y).^(1/2);
    z = 2.*p.*p.*sin(angle).*cos(angle);
end