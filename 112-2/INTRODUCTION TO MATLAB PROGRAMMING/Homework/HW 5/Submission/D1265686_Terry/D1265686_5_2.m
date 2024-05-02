a = [1 0 2];

b = [0 2 2];

A = a ~= b;
fprintf("A.");
fprintf("%d", A);
fprintf("\n\n");

B = a<b;
fprintf("B.");
fprintf("%d",B);
fprintf("\n\n");

C = a < b < a;
fprintf("C.");
fprintf("%d",C);
fprintf("\n\n");

D = a < b < b;
fprintf("D.");
fprintf("%d",D);
fprintf("\n\n");

E = a| (~a);
fprintf("E.");
fprintf("%d",E);
fprintf("\n\n");

F = b & (~b);
fprintf("F.");
fprintf("%d",F);
fprintf("\n\n");

G = a(~(~b));
fprintf("G.");
fprintf("%d",G);
fprintf("\n\n");

a = b == a;
fprintf("H.");
fprintf("%d",a);
fprintf("\n\n");


