function y=newquot(f1,x)
    h = 1e-3;
    y = (feval(f1, x + h) - feval(f1, x)) ./ h;
end