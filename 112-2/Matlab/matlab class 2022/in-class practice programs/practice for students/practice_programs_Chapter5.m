

%==========================================================================
%==========================================================================



x = 0 : pi/20 : 3 * pi;
y = sin(x);
y = y .* (y > 0); % set negative values of sin(x) to zero
figure, plot(x, y)




x = -4*pi : pi / 20 : 4*pi;
y = sin(x) ./ x;
figure, plot(x, y)


x = -4*pi : pi/20 : 4*pi;
x = x + (x == 0)*eps; % adjust x = 0 to x = eps
y = sin(x) ./ x;
figure, plot(x, y)


x = -3/2*pi : pi/100 : 3/2*pi;
y = tan(x);
figure, plot(x, y)



x = -3/2*pi : pi/100 : 3/2*pi;
y = tan(x);
y = y .* (abs(y) < 1e10); % remove the big ones
figure, plot(x, y)








tic % start
a = 0; % number >= 0.5
b = 0; % number < 0.5
for n = 1:5000
    r = rand; % generate one number per loop
    if r >= 0.5
        a = a + 1;
    else
        b = b + 1;
    end;
end;
t = toc; % finish
disp( ['less than 0.5: ' num2str(a)] )
disp( ['time: ' num2str(t)] )



r = rand(1,5000)
sum( r < 0.5 )









a = [-2 0 1 5 9];
find(a)
a = a( find(a) )


x = [8 1 -4 8 6];
find(x >= max(x))

b = 0/0
c = 6/0
x=[c b 0 1 8 9]
isinf(x)
isnan(x)
x(isnan(x)) = [ ]

isempty(x)
y=[]
isempty(y)




%==========================================================================
%==========================================================================


% Income tax the old-fashioned way
inc = [5000 10000 15000 30000 50000];
for ti = inc
    if ti < 10000
        tax = 0.1 * ti;
    elseif ti < 20000
        tax = 1000 + 0.2 * (ti - 10000);
    else
        tax = 3000 + 0.5 * (ti - 20000);
    end;
   format compact;
   disp( [ti tax] )
end;

format short



% Income tax the logical way
inc = [5000 10000 15000 30000 50000];
tax = 0.1 * inc .* (inc <= 10000);
tax = tax + (inc > 10000 & inc <= 20000).* (0.2 * (inc-10000) + 1000);
tax = tax + (inc > 20000) .* (0.5 * (inc-20000) + 3000);
disp( [inc' tax'] );





%==========================================================================
%==========================================================================












