x=0:pi/20:5*pi;

function1= @(x) exp(-0.2.*x).*sin(2.*x);
function2= @(x) exp(-0.1*x).*cos(4.*x);

f1=plot(x, function1(x));
hold on;
f2=plot(x, function2(x));
f1.Color='m';
f1.LineStyle='--';
f1.LineWidth=3;
f2.Color='b';
f2.LineStyle='-.';
f2.LineWidth=3;

title('Question 1');
xlabel('X-axis');
ylabel('Y-axis');
legend('function1', 'function2');