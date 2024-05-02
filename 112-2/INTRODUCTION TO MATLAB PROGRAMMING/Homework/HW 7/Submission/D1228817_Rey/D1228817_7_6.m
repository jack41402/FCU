
fprintf("Standard normal function at 1 is %f", std_normal_f(1));


function Y=std_normal_f(x)
    r=exp(-0.5*x^2)/sqrt(2*pi);
    t=1/(1+0.3326*x);
    
    Y=0.5-r*(0.4361836*t-0.120167*t^2+0.937298*t^3);

end