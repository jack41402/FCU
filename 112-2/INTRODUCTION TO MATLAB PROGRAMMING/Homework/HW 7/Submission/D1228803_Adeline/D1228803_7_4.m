function D1228803_7_4()
    function [x, y] = swap(x ,y)   
       temp = x;   
       x = y;  
       y = temp; 
    end 
    x = input('x = ');
    y = input('y = ');
    [x, y] = swap(x, y);
    fprintf('(x, y) = %d %d\n', x, y);
end







