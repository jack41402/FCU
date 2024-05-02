P = @(t) 197273000 ./ (1 + exp(-0.03134.*(t - 1913.25)));
year = 1790:10:2000;
now = P(year);
plot(year, now);

year = 1790;
last = 0;
P = @(t) 197273000 / (1 + exp(-0.03134*(t - 1913.25)));
while true
    now = P(year);
    if(abs(now - last) < 1)
        break
    end
    last = now;
    year = year + 1;
end

fprintf('%d', year);
