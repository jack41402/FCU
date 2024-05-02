
f=@(x) x^3;
%newquot=D1228817_newquot;

h=1;
curr=D1228817_newquot(f(1+h), f(1), h);
prev=0;
while abs(curr-prev)>10^-6
    prev=curr;
    h=h*0.1;
    curr=D1228817_newquot(f(1+h), f(1), h);

end

y=curr
    



