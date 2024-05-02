a = [1 0 2];
b = [0 2 2];

result_A = a ~= b;
result_B = a < b;
result_C = (a < b) < a;
result_D = (a < b) < b;
result_E = a | (~a);
result_F = b & (~b);
result_G = a(~(~b));
result_H = all(a == b) && all(b == a);

fprintf('A. %d %d %d\n', result_A);
fprintf('B. %d %d %d\n', result_B);
fprintf('C. %d %d %d\n', result_C);
fprintf('D. %d %d %d\n', result_D);
fprintf('E. %d %d %d\n', result_E);
fprintf('F. %d %d %d\n', result_F);
fprintf('G. %d %d\n', result_G);
fprintf('H. %d %d %d\n', result_H);
