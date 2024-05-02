a = 1;
b = 1;
fprintf(' 0\t%5d\n', a);
fprintf(' 1\t%5d\n', b);

for i = 3:21
    c = a + b;
    if i < 11
        fprintf(' %d\t%5d\n', i-1, c); 
    else
        fprintf('%d\t%5d\n', i-1, c);
    end
    a = b;
    b = c;
end
fprintf('\n');
