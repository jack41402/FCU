fprintf("Enter A\n")
a = input('');
fprintf("Enter B\n")
b = input('');
fprintf("Enter C\n")
c = input('');
p = [a b c];
root = roots(p);
root1 = root(1)
root2 = root(2)
%D = sqrt(b^2-4*a*c);
%root1 = (-b+D)/(2*a)
%root2 = (-b-D)/(2*a)
