function func(n,a)
fprintf("                  n                                  x_n\n")
for i=0:n
    x_n(i+1,1)=i;
    if i==0
        x_n(i+1,2)=0;
    elseif i==1
        x_n(i+1,2)=1.*a/2;
    else
      x_n(i+1,2)=x_n(i,2).*a.*i./((i-1).*(i+1));
    end

end
disp(rats(x_n,35))
end
