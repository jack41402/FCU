function D1265154_7_6()
    function phi_x = standard_normal_cdf(x)
        a = 0.4361836;
        b = -0.1201676;
        c = 0.937298;

        t = 1 ./ (1 + 0.3326 * x);
        r = exp(-0.5 * x.^2) / sqrt(2 * pi);

        phi_x = 0.5 - r .* (a * t + b * t.^2 + c * t.^3);
    end
    for x = 0:0.1:4
        phi_x = standard_normal_cdf(x);  
    end
    fprintf('\nΦ(1) = %.4f\n', standard_normal_cdf(1));
end
