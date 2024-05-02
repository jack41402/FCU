for i=0:1:20
    fprintf('%d %d\n',i,f(i))
end

function y=f(n)
    if n==0 || n==1   
        y=1;    
    else  
        y=f(n-1)+f(n-2);    
    end
end