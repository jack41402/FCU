function y = newqout(x,h);
f = @(x) x.^3;
y = (f(x+h) - f(x))./ h;
end