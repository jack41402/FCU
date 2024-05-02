x = 3
y = 4
[x y] = swop(3, 4);
fprintf("(x, y)= \n");
disp([x y]);
function [x y] = swop(a,b)
    x = b;
    y= a;
end

