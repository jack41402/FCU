sum=100000;
for i=1:12;
    if sum<=110000
        rate=0.01;
        interest=sum*rate;
        sum=sum+interest+1000;
        fprintf("%d %.3f %.2f %.f\n",i,rate,interest,sum)
    elseif sum>110000 &&sum<=125000
        rate=0.015;
        interest=sum*rate;
        sum=sum+interest+1000;
        fprintf("%d %.3f %.2f %.f\n",i,rate,interest,sum)
    else
        rate=0.02;
        interest=sum*rate;
        sum=sum+interest+1000;
        fprintf("%d %.3f %.2f %.f\n",i,rate,interest,sum)
    end
end