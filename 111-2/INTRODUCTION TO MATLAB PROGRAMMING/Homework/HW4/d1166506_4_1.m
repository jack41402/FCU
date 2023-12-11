a = input('') ;
b = input('') ;
c = input('') ;

if (a==0)
    if (b==0)
        if (c==0)
            fprintf("Solution indeterminate\n") ;
        else
            fprintf("There is no solution\n") ;
        end
    else
        fprintf("Only one root: equation is linear\n") ;
        x = -c/b
    end
elseif (b^2<4*a*c)
    fprintf("Complex roots\n") ;
elseif (b^2==4*a*c)
    fprintf("Equal roots\n") ;
    x = -b/(2*a)
else
    x1 = (-b + sqrt(b^2-4*a*c))/(2*a)
    x2 = (-b - sqrt(b^2-4*a*c))/(2*a)
end