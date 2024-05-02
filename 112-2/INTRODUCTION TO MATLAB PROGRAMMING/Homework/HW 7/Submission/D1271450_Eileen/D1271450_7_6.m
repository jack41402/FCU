function D1271450_7_6()
function result = standard_normal_function(x)
    a = 0.4361836;
    b = -0.1201676;
    c = 0.937298;
    
    r = exp(-0.5 * x^2) / sqrt(2 * pi);
    t = 1 / (1 + 0.3326 * x);
    
    result = 0.5 - r*(a * t + b * t^2 + c * t^3);
end
x_values = 1;
for i = 1:length(x_values)
    x = x_values(i);
    i_x = standard_normal_function(x);
    results_matrix(i, :) = [x, i_x];
end
disp('x      I(x)');
disp(results_matrix);
end
