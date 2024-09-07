A = @(n) (((-1)^n)/(2*n+1))*4;
d = 0;
for n=0:100000
    d = d+A(n);
    % rats(a(n))
    % fprintf("\n");
end
fprintf('a = \n    %f\n', d);

b = @(n) (1/((4*n-3)*(4*n-1)));
e = 0;
for n=1:100000
    e = e+b(n);
end
fprintf('b = \n    %f\n', e*8);
c = @(n,x) ((-1)^(n-1))*x^(2*n-1)/(2*n-1);
x = 1/8;
y = 1/57;
z = 1/239;
g = 0;
h = 0;
j = 0;
for n=1:10000
    g = g+c(n,x);
    h = h+c(n,y);
    j = j+c(n,z);
end
f = (6*g + 2*h + j)*4;
fprintf('c = \n    %f\n', f)
