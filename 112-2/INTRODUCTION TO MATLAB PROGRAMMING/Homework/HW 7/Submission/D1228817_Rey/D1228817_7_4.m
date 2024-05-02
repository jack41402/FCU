x=3
y=4

[x1, y1]=swop(x, y);
fprintf("(x, y)=\n         %d    %d",x1, y1)

function [xs, ys]=swop(x, y)
    
    xs=y;
    ys=x;
end