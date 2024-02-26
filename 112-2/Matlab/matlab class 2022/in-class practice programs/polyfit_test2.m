%% Polyfit for the different order of polynomial & MS error evaluation

x=1:9;
y=[ 5 6 10 20 28 33 34 36 42 ];
coeff1=polyfit(x,y,1);
coeff2=polyfit(x,y,2);
coeff3=polyfit(x,y,3);
coeff4=polyfit(x,y,4);
figure(1);subplot(221);
plot(x,y,'o',x,polyval(coeff1,x),'--*r');
title('1-st order polynomial')
subplot(222);
plot(x,y,'o',x,polyval(coeff2,x),'--+k');
title('2-nd order polynomial')
subplot(223);
plot(x,y,'o',x,polyval(coeff3,x),'--sg');
title('3-th order polynomial')
subplot(224);
plot(x,y,'o',x,polyval(coeff4,x),'--db');
title('4-th order polynomial')
%% evaluate the goodness of the fitting :
% J: square error r2: r mean square eror 
ym=mean(y);
for k=1:4
           eval(['str=','coeff',int2str(k),';']);
           J(k)=sum((polyval(str,x)-y).^2);
           S(k)=sum((y-ym).^2);
           r2(k)=1-J(k)/S(k);
end
order=[ 1 2 3 4]';
disp([ order J' r2' ])
disp(S(1))



