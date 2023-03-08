t = linspace(0, 1, 1000);
y = exp(-8*t) .* sin(9.7*t + pi/2);
plot(t, y);
xlabel('Time (s)');
ylabel('Amplitude');
title('y(t) = e^{-8t}sin(9.7t+\pi/2)');