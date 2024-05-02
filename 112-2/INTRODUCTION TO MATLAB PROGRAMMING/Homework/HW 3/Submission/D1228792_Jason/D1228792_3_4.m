t = 1790 : 10 : 2000;
y = 197273000./(1+exp(-0.03134.*(t-1913.25)));
plot(t,y)
t = 1790;
py=-2;
while true
    y = 197273000./(1+exp(-0.03134.*(t-1913.25)));
    if((y-py)<1 & (y-py)>-1)
        break
    end
    py = y;
    t = t + 1;
end
fprintf("%d\n",t);

    

