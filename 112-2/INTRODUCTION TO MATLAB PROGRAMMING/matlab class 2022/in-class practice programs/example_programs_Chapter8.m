
%% Sec. 8.1 repetited loop by using for
% binomial coefficient
ncr=1;
n=5;
r=3;
for k=1:r
    ncr=ncr*(n-k+1)/k;
end
disp(ncr)

%   An exaple in p. 181 :Update processes

K = 0.05;
F = 10;
a = 0; % start time
b = 100; % end time
time = a; % initialize time
T = 25; % initialize temperature
load train % prepare to blow the whistle
dt = input( 'dt: ' );
opint = input( 'output interval (minutes): ');
if opint/dt ~= fix(opint/dt)
    sound(y, Fs) % blow the whistle!
    disp( 'output interval is not a multiple of dt!');
end
   
clc
format bank
disp( ' Time Temperature' );
disp( [time T] ) % display initial values
for time = a+dt : dt : b
    T = T - K * dt * (T - F);
    if abs(rem(time, opint)) < 1e-6 % practically zero!
        disp( [time T] )
    end
end



%---Sec. 8.2 ------ repetited loop by using while------------------------


%   8.2.1 A guessing game

matnum = floor(10 * rand + 1);
guess = input( 'Your guess please: ' );
% is a sound data
load splat
while guess ~= matnum
    sound(y, Fs)
    if guess > matnum
        disp( 'Too high' )
    else
        disp( 'Too low')
    end;
    guess = input( 'Your next guess please: ' );
end
disp( 'At last!' )
load handel
sound(y, Fs) % hallelujah!




%--------------------------------------------------



%   8.2.3 Doubling time of an investment

a = 1000;
r = 0.1;
bal = a;
year = 0;
disp('Year Balance')
while bal < 2 * a
    bal = bal + r * bal;
    year = year + 1;
    disp( [year bal] )
end



%--------------------------------------------------


%   8.2.4 Prime numbers

%   Write your own script!





%   8.2.5 Projectile trajectory

dt = 0.1;
g = 9.8;
u = 60;
ang = input( 'Launch angle in degrees: ' );
ang = ang * pi / 180; % convert to radians
x = 0; y = 0; t = 0; % for starters
more(15)
while y >= 0
    disp( [t x y] );
    t = t + dt;
    y = u * sin(ang) * t - g * t^2 / 2;
    x = u * cos(ang) * t;
end


%--------------------------------------------------

%   Now suppose we want to plot the trajectory

dt = 0.1;
g = 9.8;
u = 60;
ang = input( 'Launch angle in degrees: ' );
ang = ang * pi / 180; % convert to radians
xp = zeros(1); yp = zeros(1); % initialize
y = 0; t = 0;
i = 1; % initial vector subscript
while y >= 0
    t = t + dt;
    i = i + 1;
    y = u * sin(ang) * t - g * t^2 / 2;
    if y >= 0
        xp(i) = u * cos(ang) * t;
        yp(i) = y;
    end
end
plot(xp, yp),grid





%--------------------------------------------------


%   8.2.7 Menus

k = 0;
while k ~= 3
    k = menu( 'Click on your option', 'Do this', ...
        'Do that', 'Quit' );
    if k == 1
        disp( 'Do this ... press any key to continue ...' )
            pause
    elseif k == 2
        disp( 'Do that ... press any key to continue ...' )
            pause
    end
end



%--------------------------------------------------



