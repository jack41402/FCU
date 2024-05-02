A = [1 4 2; 2 4 100; 7 9 7; 3 pi 42];

%a
B = A'

%b
D = A;
D(3, :) = []

%c
%x = B;
x(3, :)
x = B;

%d
sum_x = sum(x)

%e
e = A(2, :) .* B(:, 3)
