fprintf("P(2 , 3) is %6f\n",Leg(2 , 3))
function y = Leg(n ,x)
if(n ==1)
    y = x;
elseif(n == 0)
    y = 1;
else
    y = ((2.*(n-1)+1).*Leg(n-1,x).*x-(n - 1).*Leg(n-2,x))./ n;
end
end