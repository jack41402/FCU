P=@(t) 197273000./(1+ exp(-0.03134.*(t - 1913.25)));
sum=0;
last=0;
for i=1790:10:2000
    sum= sum+P(i);
    last= sum;
    fprintf('%d %1.0f\n', i, last);
end
x= 1790:10:2000;
y= P(x);
plot(x,y);

last_2=0;
c=1790;
P=@(t) 197273000/(1+ exp(-0.03134*(t - 1913.25)));
while true
    now=P(c);
    if (abs(now- last_2)<1)
        break
    end
    last_2= now;
    c=c+1;
end
fprintf('%d', c);

    

       


