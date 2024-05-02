A = [1 4 2;
     2 4 100;
     7 9 7;
     3 pi 42]
B = A'

x = B(3,1:4)
sum = sum(x)
multi = A(2,1:3).*B(1:3,3)
D = remove(A,3,1:3)