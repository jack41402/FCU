a= 2;
fprintf('n      x_n\n');
for n=0:20
    fprintf('%d      %s\n', n, rats(func(a,n),30))
end