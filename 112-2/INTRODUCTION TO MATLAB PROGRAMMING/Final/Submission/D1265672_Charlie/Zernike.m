function z = Zernike(x, y)
    p = sqrt(x.^2 + y.^2);       
    si = atan2(y, x);             
    z = 2 * (p.^2) .* sin(si) .* cos(si); 
end