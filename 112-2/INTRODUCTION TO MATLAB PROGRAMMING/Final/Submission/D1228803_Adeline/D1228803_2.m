%D1228803_2

Time = [0 1 2 3 4 5];
Temperature = [20 25 27 28 27 25];

X = Time;
%Y = log(Temperature);
Y = Temperature;
figure;
plot(X, Y, '-o');


%p = polyfit(X, Y, 1);

%b = p(1);
%log(T0) = p(2);

%T0 = exp(log_T0);
%n = 3.6;

Time_fit = linspace(0, 5, 100);
%Temperature_fit = T0 * exp(-n * Time_fit);
figure;
plot(X, Y, '-o');



