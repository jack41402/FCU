clear all;close all;
in_temp=input('  the initial value of the temperture in degree C : ');
final_temp=input('  the final value of the temperture in degree C : ');
step=input('  the step of the temperture in degree C : ');
tempc=in_temp:step:final_temp;
N=length(tempc);
tempf=zeros(size(tempc));
for i=1:N
    tempf(i)=(9/5)*tempc(i)+32;
    fprintf('   Celsius %3.2f Fahrenheit %4.2f \n',tempc(i),tempf(i)); 
end

20