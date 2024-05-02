if abs(f(1)-0.3413)<10^(-4)
   fprintf("Standard normal function at 1 is %.6f\n", f(1))
end
function y =f(x)

a = 0.4361836;

b = -0.1201676;

c = 0.937298;

r = exp(-0.5*(x^2))/sqrt(2*pi);

t = 1/(1+0.3326*x);

y = 0.5-r*(a*t+b*(t^2)+c*(t^3));
end
