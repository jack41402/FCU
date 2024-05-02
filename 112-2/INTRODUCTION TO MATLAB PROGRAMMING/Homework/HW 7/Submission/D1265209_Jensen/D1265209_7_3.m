for i=0:1:6
    x=1;
    h=10^(-i);
    d=newtq(x,h);
end
fprintf('\n%.4f',d)