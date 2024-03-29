format compact
A = [1 4 2; 2 4 100; 7 9 7; 3 pi 42];
B = log(A');

fprintf("a.\n");
C = A'

fprintf("b.\n");
D = A([1, 3:end], :)

fprintf("c.\n");
D = [D(:, 1), ones(size(D, 1), 1), D(:, 2:end)]

fprintf("d.\n");
E = A(:, [1, 3])

fprintf("e.\n");
x = B(2, :)

fprintf("f.\n");
sum_x = sum(x)

fprintf("g.\n");
A(2, :) .* B(:, 3)

fprintf("h.\n");
A(1, :) .* B(:, 3)

fprintf("i.\n");
max_value = max(max(A(1, :) .* B(:, 3)))
min_value = min(min(A(1, :) .* B(:, 3)))
sum_value = sum(sum(A(1, :) .* B(:, 3)))

