x=0.1:0.1:2000;
y=0.1:0.1:2000;
[p q]=fminbnd(cost, x, y);
R_min=q
L_mim=p
min_cost=cost(R_min, L_min)
function result=cost(L, R)
area=@(L, R) 2.*R.*L+pi.*(R.^2)./2;
if area(L, R)-2000==0
   result=(2.*L+2.*R).*40+pi.*R.*50;
end
end