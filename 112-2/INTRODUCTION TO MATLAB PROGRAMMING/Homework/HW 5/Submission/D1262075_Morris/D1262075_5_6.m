x = [1 2 5 0 5];
max_value = max(x);
max_elem = find(x == max_value);
x(max_elem) = [];
disp('x=');
disp(x);