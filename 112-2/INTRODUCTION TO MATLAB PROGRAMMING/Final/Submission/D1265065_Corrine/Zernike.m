function [p, theta] = Zernike(x, y)
    theta = atan(y/x);
    p = (x.^2+y.^2)^(1/2);
end