%% Create Fit Options and Fit Type Before Fitting  
% Load and plot the data, create fit options and fit type using the |fittype|
% and |fitoptions| functions, then create and plot the fit.   

% Copyright 2015 The MathWorks, Inc.


%% 
% Load and plot the data in |census.mat|. 
load census
plot(cdate,pop,'o')  

%% 
% Create a fit options object and a fit type for the custom nonlinear model
% $y = a(x-b)^n$, where _a_ and _b_ are coefficients and _n_ is a problem-dependent
% parameter. 
fo = fitoptions('Method','NonlinearLeastSquares',...
               'Lower',[0,0],...
               'Upper',[Inf,max(cdate)],...
               'StartPoint',[1 1]);
ft = fittype('a*(x-b)^n','problem','n','options',fo);  

%% 
% Fit the data using the fit options and a value of _n_ = 2. 
[curve2,gof2] = fit(cdate,pop,ft,'problem',2)  

%% 
% Fit the data using the fit options and a value of _n_ = 3. 
[curve3,gof3] = fit(cdate,pop,ft,'problem',3)  

%% 
% Plot the fit results with the data. 
hold on
plot(curve2,'m')
plot(curve3,'c')
legend('Data','n=2','n=3')
hold off   

