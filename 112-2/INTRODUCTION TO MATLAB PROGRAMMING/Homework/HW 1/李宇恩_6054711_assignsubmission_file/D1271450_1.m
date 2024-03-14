tiledlayout(1,2)

% Left plot
ax1 = nexttile;
t = 0:pi/5:7/pi;
xt1 = sin(t);
yt1 = cos(t);
plot3(ax1,xt1,yt1,t,'+b')
title(ax1,'one strip')

% Right plot
ax2 = nexttile;
t = 0:pi/15:23*pi;
xt2 = sin(2*t);
yt2 = cos(2*t);
plot3(ax2,xt2,yt2,t,'ok')
title(ax2,'Helix With many Turns')