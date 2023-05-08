f = @(x) exp(-0.2.*x).*sin(2.*x) ;
figure
h = animatedline ;
axis([0 5*pi -1 1]) ;
x = 0:pi/20:5*pi ;

for i=1:length(x)
    y = f(x(i)) ;
    addpoints(h , x(i) , y) ;
    drawnow
end