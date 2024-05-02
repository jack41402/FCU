for i = 1:0.1:4
    y = standardnormal(i);
    if(i == 1)
        fprintf("standard normal functioin at 1 is %.6f", y);
    end
end
function y = standardnormal(x)
a = 0.4361836;
b = -0.1201676;
c = 0.937298;
r = exp(-0.5 .* x .^ 2) ./ sqrt(2 .* pi);
t = 1 ./ (1 + 0.3326 .* x);
y = 0.5 - r .* (c .* t .^ 3 + b .* t .^2 + a .*t);
end