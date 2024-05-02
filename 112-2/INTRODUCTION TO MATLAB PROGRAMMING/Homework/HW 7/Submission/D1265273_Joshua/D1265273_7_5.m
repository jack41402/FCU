x= 3
a= b(x);
if (a-exp(x))<10^(-6)
    fprintf('The result of exponential function is %3.6f\n', a);
end


function y= b(x)
    y= 0;
    for i=0:2000
        if  (x^i)/factorial(i)>=10^(-6)
            y= y+(x^i)/factorial(i);
        else
            return;
        end
    end

end