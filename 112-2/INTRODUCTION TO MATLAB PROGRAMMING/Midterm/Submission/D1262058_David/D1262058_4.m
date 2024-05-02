fprintf("n              x_n\n");
for n = 0:20
    fprintf("%d", n);
    y = rats(func(2,n), 30);
    disp(y);
    fprintf("\n");
  
     
   
     
end