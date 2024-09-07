function y=Zernike(x,y)
    p = (x.^2+y.^2).^0.5;
    y = 2.*p.^2.*sin(atan2(y,x)).*cos(atan2(y,x));
end