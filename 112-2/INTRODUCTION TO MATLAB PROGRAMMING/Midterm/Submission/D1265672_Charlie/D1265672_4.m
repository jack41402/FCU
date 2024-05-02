n = 20;
a = 2;
fprintf("n         x_n");

for i = 0:n
    fprintf("\n%-10d", i);
    func(2, i)
end