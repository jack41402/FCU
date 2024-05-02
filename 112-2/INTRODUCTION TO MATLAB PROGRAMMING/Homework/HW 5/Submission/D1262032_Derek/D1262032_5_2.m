a = [1 0 2];
b = [0 2 2];

A = a ~= b;
B = a < b;
C = a < b < a;
D = a < b < b;
E = a | (~a);
F = b & (~b);
G = a(~(~b));
H = b == a;

disp('A.')
disp(A)
disp('B.')
disp(B)
disp('C.')
disp(C)
disp('D.')
disp(D)
disp('E.')
disp(E)
disp('F.')
disp(F)
disp('G.')
disp(G)
disp('H.')
disp(H)