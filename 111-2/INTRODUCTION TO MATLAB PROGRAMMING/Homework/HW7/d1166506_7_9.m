A = [4 -2 1 ; 6 8 -5 ; 7 9 10] ;
B = [6 9 -4 ; 7 5 3 ; -8 2 1] ;
C = [-4 -5 2 ; 10 6 1 ; 3 -9 8] ;

fprintf("A(B+C):\n");
disp(A*(B+C))
fprintf("AB+AC:\n");
disp(A*B + A*C)

fprintf("(AB)C:\n");
disp((A*B)*C)
fprintf("A(BC):\n");
disp(A*(B*C))