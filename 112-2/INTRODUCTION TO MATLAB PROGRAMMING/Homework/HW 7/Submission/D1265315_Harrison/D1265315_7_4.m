x = 3 
y = 4
[x,y] = swop(x,y);
fprintf("(x, y)=\n")
disp([x y])
function [x,y] = swop(a,b);
    x = a; y = b;
    temp = x;
    x = y;
    y = temp;
end