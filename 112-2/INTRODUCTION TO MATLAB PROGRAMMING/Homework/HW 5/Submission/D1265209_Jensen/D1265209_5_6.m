x = [1 2 5 0 5];

max_v = max(x);
max_i = find(x == max_v);

x(max_i) = [];

disp('x=');
disp(x);