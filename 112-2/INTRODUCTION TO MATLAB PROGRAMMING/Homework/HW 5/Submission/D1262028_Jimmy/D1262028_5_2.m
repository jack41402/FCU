a=[1 0 2];
b=[0 2 2];

A=a~=b;
B=a<b;
C=a<b&a;
D=a<b&b;
E=a|(~a);
F=b&(~b);
G=a(~(~b));

H= b==a;

fprintf("A. %d %d %d", A);
fprintf("\nB. %d %d %d", B);
fprintf("\nC. %d %d %d", C);
fprintf("\nD. %d %d %d", D);
fprintf("\nE. %d %d %d", E);
fprintf("\nF. %d %d %d", F);
fprintf("\nG. %d %d ", G);
fprintf("\nH. %d %d %d", H);
