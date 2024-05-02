A = [1 4 2; 2 4 100; 7 9 7; 3 pi 42];
B = A';
fprintf('B = \n')
disp(B)
D = A([1 2 4],:)
x = A(:,[3])'
x_sum = sum(x)
e = A([2],:).*B(:,[3])
