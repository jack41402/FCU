

%   10.1 UPDATE PROCESSES

%   10.1.1 Unit time steps

%   We first solve the problem using a unit time step, i.e., dt = 1.
tic
K = 0.05;
F = 10;
T = 25; % initial temperature of OJ
for time = 1:100 % time in minutes
    T = T - K * (T - F); % dt = 1
    if rem(time, 5) == 0
        disp( [time T] )
    end
end;
toc


%----------------------------------------------------

% The above script is modified to plot the result as a figure

tic
K = 0.05;
F = 10;
time = 0:100; % initialize vector time
T = zeros(1,101); % pre-allocate vector T
T(1) = 25; % initial temperature of OJ
for i = 1:100 % time in minutes
    T(i+1) = T(i) - K * (T(i) - F); % construct T
end;
disp([ time(1:5:101)' T(1:5:101)' ]); % display results
toc
plot(time, T), grid % every 5 mins


%----------------------------------------------------


%   10.1.2 Non-unit time steps


K = 0.05;
F = 10;
a = 0; % initial time
b = 100; % final time
load train
dt = input( 'dt: ');
opint = input( 'output interval (minutes): ' );
if opint/dt ~= fix(opint/dt)
    sound(y, Fs)
    disp( 'output interval is not a multiple of dt!')
    break
end;
m = (b - a) / dt; % m steps of length dt
if fix(m) ~= m % make sure m is integer
    sound(y, Fs)
    disp( 'm is not an integer - try again!' );
    break
end;
T = zeros(1,m+1); % pre-allocate (m+1) elements
time = a:dt:b;
T(1) = 25; % initial temperature
for i = 1:m
    T(i+1) = T(i) - K * dt * (T(i) - F);
end;
disp( [time(1:opint/dt:m+1)' T(1:opint/dt:m+1)'] )
plot(time, T),grid


%----------------------------------------------------


%  10.1.3 Using a function

function [time, T, m] = cooler( a, b, K, F, dt, T0 )
m = (b - a) / dt; % m steps of length dt
if fix(m) ~= m % make sure m is integer
    disp( 'm is not an integer - try again!' );
    break
end;
T = zeros(1,m+1); % pre-allocate
time = a:dt:b;
T(1) = T0; % initial temperature
for i = 1:m
    T(i+1) = T(i) - K * dt * (T(i) - F);
end;


%----------------------------------------------------


%   Suppose you want to display a table of temperatures against time at 5 minute
%   intervals, using dt = 1 and dt = 0.1.

dt = 1;
[t T m] = cooler(0, 100, 0.05, 10, dt, 25);
table(:,1) = t(1:5/dt:m+1),;
table(:,2) = T(1:5/dt:m+1),;
dt = 0.1;
[t T m] = cooler(0, 100, 0.05, 10, dt, 25);
table(:,3) = T(1:5/dt:m+1),;
format bank
disp(table)


%----------------------------------------------------



%   10.2.1 A random walk

f = zeros(1,100);
x = 40;
for i = 1:1000
    r = rand;
    if r >= 0.5
        x = x + 1;
    else
        x = x - 1;
    end
    if x ~= 0 | x ~= 100
        f(x) = f(x) + 1;
    end
end

figure, bar(f);


%----------------------------------------------------


%   10.2.2 Histograms

m = [0 25 29 35 50 55 55 59 72 75 95 100];
figure, hist(m);
[n,x] = hist(m)
figure, bar(x,n);

figure, hist(m,25);


%----------------------------------------------------


%   10.3.1 Bubble Sort

function y = bubble( x )
n = length(x);
sorted = 0; % flag to detect when sorted
k = 0; % count the passes
while ~sorted
    sorted = 1; % they could be sorted
    k = k + 1; % another pass
    for j = 1:n-k % fewer tests on each pass
        if x(j) > x(j+1) % are they in order?
            temp = x(j); % no ...
            x(j) = x(j+1);
            x(j+1) = temp;
            sorted = 0; % a swop was made
        end
    end
end;
y = x;




%----------------------------------------------------


r = rand(1,20);
z = bubble( r );



%----------------------------------------------------



%   10.3.2 MATLAB¡¦s sort

z1 = sort(r)


%----------------------------------------------------



r = [0.4175 0.6868 0.5890 0.9304 0.8462]
[y,i] = sort(r)



%----------------------------------------------------


%   10.4 STRUCTURES

student.name = 'Thandi Mangwane';
student.id = 'MNGTHA003';
student.marks = [36 49 74];

student(2).name = 'Charles Wilson'
student(2).id = 'WLSCHA007'
student(2).marks = [49 98]


course.name = 'MTH101';
course.class = student;

course(2).name ='PHY102';
course(2).class = student;

[name1, name2] = deal(course(1).class(1:2).name);



%----------------------------------------------------


%   10.5 CELL ARRAYS

%   10.5.1 Assigning data to cell arrays

%   cell indexing:
c(1,1) = {rand(3)};
c(1,2) = {char('Bongani', 'Thandeka')};
c(2,1) = {13};
c(2,2) = {student};


%   content indexing:
c{1,1} = rand(3);
c{1,2} = char('Bongani', 'Thandeka');
c{2,1} = 13;
c{2,2} = student;




b = {[1:5], rand(2); student, char('Jason', 'Amy')}


%----------------------------------------------------


%   The cell function enables you to preallocate empty cell arrays, e.g.

a = cell(3,2) % empty 3-by-2 cell array

a(2,2) = {magic(3)}


r = c{1,1}
rnum = c{1,1}(2,3)



%----------------------------------------------------

















