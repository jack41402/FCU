result_A = 1 & -1;
result_B = 13 & ~(-6);
result_C = 0 < -2 | 0;
result_D = ~[1 0 2] * 3;
result_E = 0 <= 0.2 <= 0.4;
result_F = 5 > 4 > 3;
result_G = 2 > 3 & 1;

fprintf('A. %d\n', result_A);
fprintf('B. %d\n', result_B);
fprintf('C. %d\n', result_C);
fprintf('D. ');
disp(result_D);
fprintf('E. %d\n', result_E);
fprintf('F. %d\n', result_F);
fprintf('G. %d\n', result_G);

