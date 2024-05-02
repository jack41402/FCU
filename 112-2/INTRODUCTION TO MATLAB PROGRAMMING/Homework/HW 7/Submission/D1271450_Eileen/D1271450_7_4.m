function D1271450_7_4()
function [x, y] = swap(x, y)
    temp = x; 
    x = y;   
    y = temp;
end
a = input('Enter A:');
b = input('Enter B:');
fprintf('Before swap: a = %d, b = %d\n', a, b);
[a, b] = swap(a, b);

fprintf('After swap: a = %d, b = %d\n', a, b);
end

