function D1265154_7_4() 
    function [x, y] = swap(x, y);
       temp = x;
        x = y;
        y = temp;
    end
    x = input('Enter x:');
    y = input('Enter y:');
    fprintf('Before:x=%d, y=%d' ,x,y)
    [x,y]=swap(x, y);
    fprintf('  After: x=%d, y=%d',x,y)
end
