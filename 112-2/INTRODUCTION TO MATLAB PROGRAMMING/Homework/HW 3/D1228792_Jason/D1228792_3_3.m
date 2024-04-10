asset = 100000;
for i=1:12
    if(asset <= 110000)
        rate = 0.01;
        interest = asset .* rate;
        asset = asset .*1.01;
    elseif(asset <= 125000 & asset >110000)
        rate = 0.015;
        interest = asset .* rate;
        asset = asset .*1.015;
    else
        rate = 0.02;
        interest = asset .* rate;
        asset = asset .*1.02;
    end
    asset = asset + 1000;
    fprintf("%d %.2f %.2f %.2f\n",i,rate,interest,asset)
end