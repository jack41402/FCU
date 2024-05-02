for i=0:1:6
    x=1;
    h=10^(-i);
    d=newquot(x, h);
end
fprintf("y=\n   %.4f\n", d)