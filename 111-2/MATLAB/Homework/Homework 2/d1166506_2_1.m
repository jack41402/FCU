A = [3 7 -4 12 ; -5 9 10 2 ; 6 13 8 11 ; 15 5 4 1] ;
B = A(: , 2:4) ;
C = A(2:4, :) ;
D = A(1:2, 2:4) ;

fprintf ("A=\n") ;
disp(A) ;
fprintf ("B=\n") ;
disp(B) ;
fprintf ("C=\n") ;
disp(C) ;
fprintf ("D=\n") ;
disp(D) ;

A(A<0) = 0 ;
fprintf ("A=\n") ;
disp(A) ;