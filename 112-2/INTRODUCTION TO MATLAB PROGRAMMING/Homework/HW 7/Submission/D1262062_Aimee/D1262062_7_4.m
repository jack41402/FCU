x = 3
y = 4
[x, y] = swop(x, y);
disp("(x, y)=")
disp([x, y])

function [x, y] = swop(x, y)
    temp = x;
    x = y;
    y = temp;
end