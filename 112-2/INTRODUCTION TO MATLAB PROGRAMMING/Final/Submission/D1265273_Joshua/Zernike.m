function Z = Zernike(x, y)
    p = (x.^2+y.^2).^(1/2);
    c= atan2(y, x);
    Z = 2.*p.^2.*sin(c).*cos(c);
end