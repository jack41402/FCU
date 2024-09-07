x=0:pi/20:5*pi;
y1=@(x) exp(-0.2.*x).*sin(2.*x);
figure1=plot(x, y1(x));
hold on
y2=@(x) exp(-0.1.*x).*cos(4.*x);
figure2=plot(x, y2(x));
legend("function 1", "function 2")
title("Question 1")
xlabel("X-axis")
ylabel("Y-axis")
figure1.LineStyle="--";
figure1.LineWidth=3;
figure1.Color="magenta";
figure2.LineStyle="-.";
figure2.LineWidth=3;
figure2.Color="blue";
legend_handle=legend('show');

