x = 3 ;
if (abs(exp(x)-exponential(x))<1e-6)
    fprintf("The result of exponential function is %f\n" , exponential(x)) ;
else
    fprintf("Valid false\n") ;
end

function y = exponential(x)
    y = 0 ;
    num = 0 ;
    term = 1e9 ;
    while (term>1e-6)
        term = x^num/factorial(num) ;
        y = y + term ;
        num = num + 1 ;
    end
end