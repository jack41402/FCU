for i = 0:1:6
    x=1;
    h = 10^(-i);
    a = D1262028_newquot(x, h);
end
fprintf("\n%.4f", a)