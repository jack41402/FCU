% Function file newquot_handel.m
function df=newquot_handel(fn,x)
h = 10e-6;
df = (feval(fn, x + h) - feval(fn, x)) ./ h;