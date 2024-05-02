A = [1, 4, 2; 2, 4, 100; 7, 9, 7; 3, pi, 42];

fprintf('a.');
B = A'

fprintf('b.')
D = A;
D(2, :) = []

fprintf('c.')
x = B(3, :)

fprintf('d.')
sum_x = sum(x)

fprintf('e.')
e = A(2, :) .* B(:, 3)