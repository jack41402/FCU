clear all;close all;
x = -pi:pi/10:pi; % provide more detail for the vector 
xs=size(x);

       y = sin(x);
       plot(x,y,'--rs','LineWidth',2,...
                       'MarkerEdgeColor','k',...
                       'MarkerFaceColor','g',...
                       'MarkerSize',10)
xlabel('x-value','Color','r','fontsize',20);ylabel('sinx');
axis([-3.5 3.5 -1.2 1.2]);