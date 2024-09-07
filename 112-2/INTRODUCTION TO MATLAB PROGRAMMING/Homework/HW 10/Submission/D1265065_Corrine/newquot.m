function df=newquot(fn,x)
h = 1e-3;
df = (feval(fn, x + h) - feval(fn, x)) ./ h;
end
