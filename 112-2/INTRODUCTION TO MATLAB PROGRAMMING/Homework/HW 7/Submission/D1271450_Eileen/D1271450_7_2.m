f = @(x) 1 + exp(-0.2*x) * sin(x+2);
c=2.5;
fun_p=@(x)1+exp(-0.2*x).*sin(x+c);
[x_min, y_min] = fminbnd(f, 0, 10)
[x_min_parametric,y_min_parametric]=fminbnd(fun_p,0,10)
figure;
hold on;
fplot(f, [0, 10]);
fplot(fun_p,[0,10]);
plot(x_min, y_min, 'ro');
yticks(0.4:0.2:1.8);
xlabel('x');
ylabel('y');
legend('y = 1 + exp(-0.2*x) * sin(x+2)', 'y = 1 + exp(-0.2x*sin(x+c) (c=2.5)', 'Minimum Point', 'Location', 'northwest');
hold off;
