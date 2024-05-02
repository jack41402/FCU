x = [1 2 5 0 5];
max_value = max(x);
indices_to_remove = find(x == max_value);
x(indices_to_remove) = []
