a = [1 0 2];
b = [0 2 2];
A = a ~= b;
fprintf("A.")
disp(A)
B = a < b;
fprintf("B.")
disp(B)
C = (a < b < a);
fprintf("C.")
disp(C)
D = (a < b < b);
fprintf("D.")
disp(D)
E = a | (~a);
fprintf("E.")
disp(E)
F = b & (~b);
fprintf("F.")
disp(F)
G = a(~(~b));
fprintf("G.")
disp(G)
H = b == a;
fprintf("H.")
disp(H)