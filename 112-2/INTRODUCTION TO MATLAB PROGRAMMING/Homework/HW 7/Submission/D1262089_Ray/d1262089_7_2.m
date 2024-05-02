f=@(x) 1+exp(-0.2*x).*sin(x+2);
         [x,y] = fminbnd(f,0,10);
         fprintf("(x,y)=(%f,%f)\n",x,y)
          y=0:0.1:10;
        plot(y,f(y))
hold on
f2=@(x,c) 1+exp(-0.2*x).*sin(x+c);
         c=2.5;
f3=@(x) f2(x,c) ;        
         [a,b] = fminbnd(f3,0,10);
         fprintf("(x,y)=(%f,%f)",a,b)
          d=0:0.1:10;
        plot(d,f3(d))


