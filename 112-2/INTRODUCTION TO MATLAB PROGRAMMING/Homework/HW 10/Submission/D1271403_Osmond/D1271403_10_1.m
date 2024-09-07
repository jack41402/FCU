x = 0:pi/20:5*pi;
function1= @(x)exp(-0.2.*x).*sin(2.*x);
function2= @(x)exp(-0.1.*x).*cos(4.*x);
osmond=plot(x,function1(x));
hold on 
Rey=plot(x,function2(x));

osmond.LineStyle="--";
osmond.Color="m";
osmond.LineWidth=2;
Rey.LineStyle="-.";
Rey.Color="b";
Rey.LineWidth=2;
xlabel('X-axis')
ylabel('Y-axis')
title('Question 1')
legend('function1','function2')