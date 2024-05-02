x = [1 2 5 0 5];

% Find the index of the largest element(s)
max_val = max(x);
max_indices = find(x == max_val);

% Remove the largest element(s)
x(max_indices) = [];

disp('x=');
disp(x);