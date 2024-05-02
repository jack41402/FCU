A = 1 & -1;
fprintf("A.");
fprintf("%d\n\n",A);

B = 13 & ~(-6);
fprintf("B.");
fprintf("%d\n\n",B);

C = 13 & ~(-6);
fprintf("C.");
fprintf("%d\n\n",C);

v = [1,0,2];
D = ~v * 3; 
fprintf("D.");
fprintf("%d",D);
fprintf("\n\n");

E = 0 <= 0.2 <= 0.4;
fprintf("E.");
fprintf("%d\n\n",E);

F = 5 > 4 > 3;
fprintf("F.");
fprintf("%d\n\n",F);

G = 2 > 3 &1;
fprintf("G.");
fprintf("%d\n\n",G);
