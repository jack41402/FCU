%% Fit a Cubic Polynomial Specifying Normalize and Robust Options  
% Load some data and fit and plot a cubic polynomial with center and scale
% (|Normalize|) and robust fitting options.   

% Copyright 2015 The MathWorks, Inc.


%%  
load census;
f=fit(cdate,pop,'poly3','Normalize','on','Robust','Bisquare')
plot(f,cdate,pop)   

