x = 0:0.1:4 ;
if (abs(stdnorm(1)-0.3413)<10-5)
    fprintf("Standard normal fucntion at 1 is %f\n" , stdnorm(1)) ;
else
    fprintf("Valid false\n") ;
end

function y = stdnorm(x)
    a = 0.4361836 ;
    b = -0.1201676 ;
    c = 0.937298 ;
    r = exp(-0.5*(x.^2))./(sqrt(2*pi)) ;
    t = 1/(1+0.3326*x) ;
    y = 0.5-r*(a.*t+b.*t.^2 + c.*t.^3) ;
end