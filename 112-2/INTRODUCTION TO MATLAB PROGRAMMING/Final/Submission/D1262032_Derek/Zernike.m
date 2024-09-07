function z = Zernike(x, y)
    f1 = sqrt(x.^2 + y.^2);       
    f2 = atan2(y, x);             
    z = 2 * (f1.^2) .* sin(f2) .* cos(f2); 
end