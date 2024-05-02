b=1;
c=a(b);
fprintf('Standard normal function at %d is %3.6f\n', b, c)

function y= a(x)
    a= 0.4361836;
    b= -0.1201676;
    c= 0.937298;
    r= exp((-0.5)*(x^2))/((2*pi)^(1/2));
    t= 1/(1+0.3326*x);
    y= 0.5-r*(a*t+b*t^2+c*t^3);
end