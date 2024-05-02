% Given vectors
a = [1 0 2];
b = [0 2 2];

% (a) a~=b
result_a = a ~= b;

% (b) a<b
result_b = a < b;

% (c) a<b<a
result_c = a < b & b < a;

% (d) a<b<b
result_d = a < b & b < b;

% (e) a | (~a)
result_e = a | (~a);

% (f) b & (~b)
result_f = b & (~b);

% (g) a(~(~b))
result_g = a(~(~b));

% (h) a=b==a
result_h = ( b == a);

% Display results
disp('A.');
disp(result_a);
disp('B.');
disp(result_b);
disp('C.');
disp(result_c);
disp('D.');
disp(result_d);
disp('E.');
disp(result_e);
disp('F.');
disp(result_f);
disp('G.');
disp(result_g);
disp('H.');
disp(result_h);