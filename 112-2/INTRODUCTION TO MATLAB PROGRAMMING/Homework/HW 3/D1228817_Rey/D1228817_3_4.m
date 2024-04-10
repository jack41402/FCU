P=@(t) 197273000./(1+exp((-0.03134)*(t-1913.25)));
t=1790:10:2000;
a=P(t);

plot(t, a);

 now=1791;
 last=1790;
while true

   if abs(P(now)-P(last))<1
       fprintf("Steady at %d", now);
       break;
   end
   now=now+1;
   last=last+1;

end
