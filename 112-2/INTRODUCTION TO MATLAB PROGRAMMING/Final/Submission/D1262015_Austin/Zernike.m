% Zernike.m

function Z = Zernike(theta, rho)
    Z = 2 * rho.^2 .* sin(theta) .* cos(theta);
end
