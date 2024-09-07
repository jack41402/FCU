function Z = Zernike(X, Y)
    angle = atan2(Y, X);
    p = sqrt(X.^2 + Y.^2);
    Z = 2 .* p.^2 .* sin(angle) .* cos(angle);
end