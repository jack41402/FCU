x = [1 2 5 0 5];


max_indices = find(x == max(x));


x(max_indices) = [];


disp(x);
