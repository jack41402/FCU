x= 3
y= 4
%disp(swop(x, y))
swop(x_1, y_1);

function [a,b]= swop(x, y)
   a= y;
   b= x;
   fprintf('(x, y)= \n     %d    %d\n', a, b);
end