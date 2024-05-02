a= [1 0 2];
b= [0 2 2];
A= a~=b;
fprintf("A. %d%d%d", A)
B= a<b;
fprintf("\nB. %d%d%d", B)
C= a<b<a;
fprintf("\nC. %d%d%d", C)
D= a<b<b;
fprintf("\nD. %d%d%d", D)
E= a|(~a);
fprintf("\nE. %d%d%d", E)
F= b & (~b);
fprintf("\nF. %d%d%d", F)
G= a(~(~b));
fprintf("\nG. %d%d%d", G)
c=b;
H= c==a;
fprintf("\nH. %d%d%d", H)
