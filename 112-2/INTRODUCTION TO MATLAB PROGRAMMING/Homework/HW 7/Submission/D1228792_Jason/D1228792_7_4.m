x = 3;
y = 4;
fprintf("x =\n\t %d\ny =\n\t %d\n",x,y)
[x y] = swop(x, y);
fprintf("(x, y)=\n\t %d\t  %d\n",x,y)
function [x y] = swop(a, b);
    x = b;
    y = a;
end