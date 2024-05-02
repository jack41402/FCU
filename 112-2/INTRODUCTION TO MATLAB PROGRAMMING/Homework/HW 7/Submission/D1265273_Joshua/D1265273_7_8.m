x= 3;
n= 2;
c= P(n, x);
p_2= (3*(x^2)-1)/2;
if c- p_2==0
    fprintf('P(2,3) is %2.6f', P(n, x));
end
function y= P(a, b)
    if a==0
        y=1;
    elseif a==1
        y=b;
    else  
    y= (((2*a)-1)*b*P(a-1, b)- (a-1)*P(a-2, b))/a;
    end
end
