a = 0.4361836;
b = -0.1201676;
c = 0.937298;
r = exp(-0.5.*x.^2)./sqrt(2.*pi);
t = 1./(1+0.3326.*x);
x = 0:0.1:4;
    y = sta(a,b,c,r,t);
    x = 1;
    y = sta(a,b,c,r,t);
    fprintf("Standard normal function at %d is %.6f\n",x,y);
   

function y = sta(a ,b ,c ,r ,t)
    y = 0.5-r.*(a.*t+b.*t.^2+c.*t.^3);
end