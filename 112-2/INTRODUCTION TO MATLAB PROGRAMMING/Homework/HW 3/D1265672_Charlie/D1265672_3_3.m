b = 100000;
fl = 1;
r = 0;
for n = 1:12
    if b <= 110000
        r = b*0.01;
        b = b + r;
        k="0.01";
    elseif b > 110000 && b <= 125000
        r = b*0.015;
        b = b + r;
        k="0.015";
    elseif b >125000
        r = b*0.02;
        b = b + r;
        k="0.02";
    end
    b = b + 1000;
    fprintf("%d %s %.2f %.2f\n", n, k, r, b+1000)

end