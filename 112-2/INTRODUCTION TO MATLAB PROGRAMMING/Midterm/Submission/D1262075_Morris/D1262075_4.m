fprintf('n                     x_n\n');
for i =0:1:20;
    a = 2;
    ans = func(a,i);
   b = rats(ans,35);
   fprintf('%d    %s\n',i,b);
end