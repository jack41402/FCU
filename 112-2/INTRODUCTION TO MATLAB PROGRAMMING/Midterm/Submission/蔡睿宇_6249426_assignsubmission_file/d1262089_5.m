clear all
clc
R=0:0.1:100;
min(f(R))
function y=f(R)
L=(2000-pi.*R.^2)/(2.*R);
y=50.*pi.*R+(4.*R+2.*L).*40;
end

