a = [1 0 2];
b = [0 2 2];
fprintf("A. %d %d %d\n\n",a ~= b);
fprintf("B. %d %d %d\n\n",a < b);
fprintf("C. %d %d %d\n\n",a < b < a);
fprintf("D. %d %d %d\n\n",a < b < b);
fprintf("E. %d %d %d\n\n",a | (~a));
fprintf("F. %d %d %d\n\n",b & (~b));
fprintf("G. %d %d\n\n",a(~(~b)));
a = b == a;
fprintf("H. %d %d %d\n\n",a);