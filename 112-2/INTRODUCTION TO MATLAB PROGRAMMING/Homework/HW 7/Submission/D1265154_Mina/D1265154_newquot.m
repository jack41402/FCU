function D1265154_newquot()
function y = f(x)
    y = x.^3;
end
x = 1;
h = 1e-6;
derivative_estimate = (f(x + h) - f(x)) / h;
fprintf('Estimated derivative = %.4f\n', derivative_estimate);



end