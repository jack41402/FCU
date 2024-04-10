years=1790:10:2000;
populations=0;

for i=1:length(years)
    t=years(i)
    P=197273000/(1+exp(-0.03134*(t-1913.25)));
    populations(i)=P
end

plot(years,populations);

disp("year population");
for i=1:length(years)
fprintf("%d %f\n",years(i),populations(i))

end
year=1790;
last=0;
 P = @(t) 197273000/(1+exp(-0.03134*(t-1913.25)));
while true
    now=P(year);
    if(abs(now-last)<1)
        break
    end
    last=now;
    year=year+1;
end
fprintf("year of steady state : %d",year)