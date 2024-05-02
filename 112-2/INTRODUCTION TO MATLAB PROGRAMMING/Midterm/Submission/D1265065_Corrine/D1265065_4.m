format rat
fprintf('n       x_n\n');
for j = 0:20
ans = (j.*func(j))./myfactorial(j);
fprintf('%d       %d\n', j, ans);
end
function a = myfactorial(i)
a = 0; 
for i = 0:20
    a = a.*i; 
end
end