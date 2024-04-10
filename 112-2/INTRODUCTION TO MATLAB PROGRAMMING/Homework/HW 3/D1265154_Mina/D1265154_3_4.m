P = @(t) 197273000 ./ (1 + exp(-0.03134 * (t - 1913.25)));
a = P(1900);
x = 1790;

last = -1;

now = 0;

while true

now = P(x);

if (abs (now-last) <1);

break
end
last = now;
x= x + 1;

end
x
x = 1790:10:2000;
y = P(x);
plot(x, y);