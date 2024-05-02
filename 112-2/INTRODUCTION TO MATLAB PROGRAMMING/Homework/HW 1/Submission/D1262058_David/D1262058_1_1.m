tiledlayout(1,5)

% Left plot
ax1 = nexttile;
t = 0:pi/20:10*pi;
xt1 = sin(t);
yt1 = cos(t);
plot3(ax1,xt1,yt1,t,':')
title(ax1,'Helix With 5 Turns')

% Right plot
ax2 = nexttile;
t = 0:pi/20:10*pi;
xt2 = sin(2*t);
yt2 = cos(2*t);
plot3(ax2,xt2,yt2,t)
title(ax2,'Helix With 10 Turns')