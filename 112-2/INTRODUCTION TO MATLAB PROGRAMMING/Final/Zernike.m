function z = Zernike(x, y)
    rho = sqrt(x.^2 + y.^2);
    theta = atan2(y, x);
    z = 2.*rho.^2.*sin(theta).*cos(theta);
end