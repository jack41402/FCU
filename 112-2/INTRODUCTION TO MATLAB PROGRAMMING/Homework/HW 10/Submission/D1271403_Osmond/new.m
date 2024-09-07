function y=new(f,x)
    h=10^-3;
    y=(f(x+h)-f(x))./h;

end