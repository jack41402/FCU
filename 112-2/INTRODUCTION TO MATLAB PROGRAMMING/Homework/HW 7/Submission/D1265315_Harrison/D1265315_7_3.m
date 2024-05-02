h = 1;
x = 1;
while(h>=10^-6)
    y = newquot(x,h);
    h = h*10^-1;
end
fprintf("y = \n\t%.5f\n",y)