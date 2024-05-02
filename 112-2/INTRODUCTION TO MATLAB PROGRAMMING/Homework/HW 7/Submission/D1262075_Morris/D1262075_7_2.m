
f2=@(x) 1+exp(-0.2.*x ).*sin(x+2);
X = fminbnd(f2,0,10)
y=0:0.1:10;
fplot(f2, [0 10]);
%plot(y,1+exp(-0.2.*y ).*sin(y+2))
hold on;
c = 2.5; 
f = @(x) 1+exp(-0.2.*x ).*sin(x+c);  
Z = fminbnd(f,0,10)

fplot(f,[0,10])