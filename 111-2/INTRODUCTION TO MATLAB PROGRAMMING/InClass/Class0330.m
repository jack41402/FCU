A = [1 4 2 ; 2 4 100 ; 7 9 7 ; 3 pi 42] ;
B = log(A')
C = A'
D = [A(1,:) ; A(3:end,:)]
D = [D(1,:) ; ones(1 , size(D , 2)) ; D(2:end,:)]
E = A(:,[1 3])
x = B(2,:)
fprintf("Sum of all elements of x: %f\n" , sum(x)) ;
