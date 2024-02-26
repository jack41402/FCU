function [xm, xn]=mnn(x)
% 
sx=length(x);
xm=x(1);xn=x(1);
for i=2:sx
    if x(i)>xm
        xm=x(i);
    elseif x(i)<xn
        xn=x(i);
    end
end

    
    