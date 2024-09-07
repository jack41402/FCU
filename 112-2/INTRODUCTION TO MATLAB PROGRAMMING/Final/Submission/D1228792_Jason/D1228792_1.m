close all;clear all;
x = 0:0.004:1;
B1=bell(0,x);
B2=bell(1,x)+1;
B3=bell(2,x)+1;
B4=bell(3,x)+1;
a = plot(x,B1,"blue");
hold on;
b = plot(x,B2,"green");
c = plot(x,B3,"red");
d = plot(x,B4,"black");
a.LineStyle = "-";
a.LineWidth = 3;
b.LineStyle = '--';
b.LineWidth = 3;
c.LineStyle = ':';
c.LineWidth = 3;
d.LineStyle = "-.";
d.LineWidth = 3;
legend('B1(x)','B2(x)','B3(x)','B4(x)')
function y = bell(n,x)
    if(x == 0)
        y = 1;
    else
        y=0;
        k = 0;
        previous = 1;
        while(k<=n)
            y = y + previous.*(factorial(n)./(factorial(n-k).*factorial(k))).*x.^(n-k);
            previous = y;
            k = k + 1;
        end
    end
end


