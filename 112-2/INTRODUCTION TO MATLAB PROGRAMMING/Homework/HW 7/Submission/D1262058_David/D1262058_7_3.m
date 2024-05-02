x = 1;
h = 1;
while(h>=1e-6)
    y = newqout(x,h);
    h = h .* 0.1;
end
fprintf("y=\n%.4f", y);