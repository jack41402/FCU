a = input('Enter the value of a: ');
b = input('Enter the value of b: ');
c = input('Enter the value of c: ');

D = b^2 - 4*a*c;
root1 = (-b + sqrt(D)) / (2*a);
root2 = (-b - sqrt(D)) / (2*a);

fprintf('root1: %f\n', root1);
fprintf('root2: %f\n', root2);
