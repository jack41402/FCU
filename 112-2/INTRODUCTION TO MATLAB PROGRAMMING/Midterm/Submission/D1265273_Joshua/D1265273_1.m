g = -pi/2 : pi/20 : pi/2;g = -pi/2 : pi/20 : pi/2;
t = 0: 0.2: 4;
e = 2;
d = 5;
fun = @(x) (exp(-0.2.*t).*sin(e.*x)+log(t+1)).*(cos(2.*x)).^2;
A = fun(g);
fprintf('a= \n')
fprintf(' Colums 1 through 10\n')
for i=1:10
    fprintf(' %1.4f  ', A(i))
end
fprintf('\n Colums 11 through 20\n')
for i=11:20
    fprintf(' %1.4f  ', A(i))
end
fprintf('\n Colums 21\n')
fprintf(' %1.4f\n ', A(21))


fun_2 = @(x) ((asin(d*t))+log(t.^2+2.*t+1)).*tan(x/2);
B = complex(fun_2(g));
fprintf('b= \n')
fprintf(' Colums 1 through 5\n')
for i=1:5
    fprintf(' %1.4f ',B(i))
end
fprintf('\n Colums 6 through 10\n')
for i=6:10
    fprintf(' %1.4f  ', B(i))
end
fprintf('\n Colums 11 through 15\n')
for i=11:15
    fprintf(' %1.4f  ', B(i))
end
fprintf('\n Colums 16 through 20\n')
for i=16:20
    fprintf(' %1.4f  ', B(i))
end
fprintf('\n Colums 21\n')
fprintf(' %1.4f \n', B(21))


fun_3 = @(x) (exp(t)+sin(x))./e;
C = fun_3(g);
fprintf('c= \n')
fprintf(' Colums 1 through 10\n')
for i=1:10
    fprintf(' %1.4f  ', C(i))
end
fprintf('\n Colums 11 through 20\n')
for i=11:20
    fprintf(' %1.4f  ', C(i))
end
fprintf('\n Colums 21\n')
fprintf(' %1.4f\n ', C(21))


t = 0: 0.2: 4;
e = 2;
d = 5;
fun = @(x) (exp(-0.2.*t).*sin(e.*x)+log(t+1)).*(cos(2.*x)).^2;
a=fun(g);
fun_2 = @(x) ((asin(d.*t))+log(t.^2+2.*t+1)).*tan(x/2);
b= complex(fun_2(g))
fun_3 = @(x) (exp(t)+sin(x))./e;
c=fun_3(g)