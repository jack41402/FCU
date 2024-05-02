for i=0:20
fprintf('%d    %d\n', i, a(i))
end
function b= a(n)
        if n==0 || n==1
            b=1;
        else 
            b=a(n-1)+a(n-2);
        end

end