t = 1790:10:2000;
P = 197273000./(1 + exp(-0.03134*(t-1913.25)));
%plot(t, P);

year = 1790;
p = @(T) 197273000 / (1 + exp(-0.03134*(T-1913.25)));
now =0;
last = 0;
while true 
    now = p(year);
    if (abs(now - last) < 1)
        break
    end 
    last = now;
    year = year + 1;
end
year
