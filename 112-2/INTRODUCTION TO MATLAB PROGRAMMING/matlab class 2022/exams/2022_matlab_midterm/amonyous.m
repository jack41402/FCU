function output = amonyous(input)
global a;
output = a.^input./factorial(input+1);
end