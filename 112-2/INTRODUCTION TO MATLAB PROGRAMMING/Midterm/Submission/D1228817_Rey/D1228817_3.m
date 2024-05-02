A=[1 4 2; 2 4 100; 7 9 7; 3 pi 42];

fprintf("a.\n");
B=A'

fprintf("b.\n");
D=A;
D(3, :)=[]

fprintf("c.\n");
x=B(3, :)

fprintf("d.\n");
x_sum=sum(x)

fprintf("e.\n");
e=A(2, :).*B(:, 3)