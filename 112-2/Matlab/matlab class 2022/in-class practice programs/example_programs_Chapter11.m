

%   11.1 SYNTAX ERRORS

2*(1+3

%-----------------------

disp(['the answer is ' num2str(2)]

%-----------------------

x = 0:pi/20:3*pi;
y = sin(x);
x = 0:pi/40:3*pi;
plot(x,y)


%-----------------------

%   11.3 ROUNDING ERROR

x = 0.1;
while x ~= 0.2
    x = x + 0.001;
    fprintf( '%g %g\n', x, x - 0.2 )
end


%-----------------------

x = 0.1;
while x <= 0.2
    x = x + 0.001;
    fprintf( '%g %g\n', x, x - 0.2 )
end



%-----------------------


x = 0.1;
while abs(x - 0.2) > 1e-6
    x = x + 0.001;
    fprintf( '%g %g\n', x, x - 0.2 )
end



%-----------------------


