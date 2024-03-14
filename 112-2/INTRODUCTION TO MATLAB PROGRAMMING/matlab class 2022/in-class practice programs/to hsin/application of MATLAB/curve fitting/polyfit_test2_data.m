
[b m]=meshgrid(1.7:0.05:1.9,0.8:0.05:1);
J=(b-2).^2+(5.*m+b-6).^2+(10.*m+b-11).^2;
figure(1),surface(b,m,J)
;view(-35,35);colormap default

[b m]=meshgrid(1.7:0.05:1.9,0.9);
J=(b-2).^2+(5.*m+b-6).^2+(10.*m+b-11).^2;
figure(2),plot(b,J)

