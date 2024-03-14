%    Write a function file stats.m:

function [avg, stdev] = stats( x ) % function definition line
%   STATS Mean and standard deviation % H1 line
%   Returns mean (avg) and standard % Help text
%   deviation (stdev) of the data in the
%   vector x, using Matlab functions

avg = mean(x); % function body
stdev = std(x);