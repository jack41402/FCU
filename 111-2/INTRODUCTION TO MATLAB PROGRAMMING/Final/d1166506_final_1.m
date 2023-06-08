P0 = @(x) x.^0 ;
P1 = @(x) x ;
P2 = @(x) 0.5.*(3.*x.^2-1) ;
P3 = @(x) 0.5.*(5.*x.^3-3.*x) ;
P4 = @(x) (1/8).*(35.*x.^4-30.*x.^2+3) ;
P5 = @(x) (1/8).*(63.*x.^5-70*x.^3+15.*x) ;

% (a)
x = -1:0.004:1 ;
plot(x , P0(x))
hold on
plot(x , P1(x))
hold on
plot(x , P2(x))
hold on
plot(x , P3(x))
hold on
plot(x , P4(x))
hold on
plot(x , P5(x))
hold on
title('Legendre Polynomials')
xlabel('x')
ylabel('Pn(x)')
legend('P0' , 'P1' , 'P2' , 'P3' , 'P4' , 'P5')
hold off

% (b)
figure
plot(x , P4(x) , 'LineStyle', '--' , 'LineWidth' , 2)
