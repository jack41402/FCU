A = [1 4 2; 2 4 100; 7 9 7; 3 pi 42];
B = transpose(A)
A(3,:) = [] 
D = A
x = B(3,:)
x_sum = sum(x)
e = A(2,:).*B(:,3)