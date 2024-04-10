unit = [200 500 700 1000 1500];
fprintf("charge =\n");

for i=1:5
    if (unit(i)<=500);
        ch = 5 + (unit(i)./100.*2);
    elseif(500<unit(i) && unit(i) <= 1000)
        ch = 15 + (unit(i)./100-5).*5;
    else
        ch = 40 + (unit(i)./100-10).*10;
    end
    fprintf("%d ", ch);
end