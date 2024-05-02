a = [1 0 2];
b = [0 2 2];
ans1 = a ~= b;
fprintf('A. ')
fprintf('%d ',ans1)
ans2 = a < b;
fprintf('\nB. ')
fprintf('%d ',ans2)
ans3 = a < b < a;
fprintf('\nC. ')
fprintf('%d ',ans3)
ans4 = a < b < b;
fprintf('\nD. ')
fprintf('%d ',ans4)
ans5 = a | (~a);
fprintf('\nE. ')
fprintf('%d ',ans5)
ans6 = b & (~b);
fprintf('\nF. ')
fprintf('%d ',ans6)
ans7 = a(~(~b));
fprintf('\nG. ')
fprintf('%d ',ans7)
ans8 = b == a;
fprintf('\nH. ')
fprintf('%d ',ans8)