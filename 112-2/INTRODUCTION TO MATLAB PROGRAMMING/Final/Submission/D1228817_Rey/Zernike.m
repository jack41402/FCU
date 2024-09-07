function Z=Zernike(X, Y)

Z=2.*(X.^2+Y.^2).*sin(atan2(Y./X)).*cos(atan2(Y./X));

end