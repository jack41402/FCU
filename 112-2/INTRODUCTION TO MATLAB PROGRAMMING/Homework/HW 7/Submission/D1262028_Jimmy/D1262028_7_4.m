x = input("x: ");
y = input("y: ");

swop(x, y)
function swop(x, y)
    temp = x;
    x = y;
    y = temp;
    fprintf('after(x, y) (%d, %d)', x, y);
end