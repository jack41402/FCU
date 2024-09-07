a = 4 .* arc(1);
fprintf("a = \n    %.4f\n",a)
k = 1;
b = 0;
while(abs((b .* 8) - a) >= 0.00006)
    yn = 1 ./ (k .* (k + 2));
    b = b + yn;
    k = k + 4;
end
b = b .* 8;
fprintf("b = \n    %.4f\n",b)
c = 4 .* (6 .* arc(1 ./ 8) + 2 .* arc(1 ./ 57) + arc(1 ./ 239));
fprintf("c = \n    %.4f\n",c)
function  y = arc(x)
    y = x;
    for i = 1 : 1 : 20000
        xn = (-1) .^ i .*(x .^ (2 .* i + 1)) ./ (2 .* i + 1);
        y = y + xn;
    end
end