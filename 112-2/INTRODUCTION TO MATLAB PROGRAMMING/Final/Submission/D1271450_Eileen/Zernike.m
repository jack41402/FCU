function D1271450_3()
[X,Y,Z] = meshgrid(--2:0.19:2,-1:0.095:1,-5:5:5);
P = atan2(Y,X);
surf(X,Y,P);
view(-180,+180);