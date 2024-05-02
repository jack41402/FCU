A = [1,4,2;2,4,100;7,9,7;3,pi,42];
fprintf("a.\n");
B = A'

fprintf("b.\n")
D=A([1 2 4],:)

fprintf("c.\n")
X=B(3,:)

fprintf("d.\n")
X_sum = sum(X)

fprintf("e.\n")
e=A(2, :).*B(:,3)
