A = [1 4 2;2 4 100;7 9 7;3 pi 42];
B = A';
fprintf('B = \n');
disp(B);
A(3,:) = [];
fprintf('D = \n');
disp(A);
B(1:2,:) = [];
fprintf('x = \n');
disp(B);
x_sum = sum(B)
A = [1 4 2;2 4 100;7 9 7;3 pi 42];
B = A';
D = A(2,:);
E = B(:,3);
e = D.*E