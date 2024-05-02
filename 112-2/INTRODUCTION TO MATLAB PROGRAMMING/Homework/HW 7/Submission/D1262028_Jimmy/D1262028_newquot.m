function y=newquot(x,h)
    f=@(x) x^3;
    y = (feval(f,x+h)-feval(f,x))/h;
end
