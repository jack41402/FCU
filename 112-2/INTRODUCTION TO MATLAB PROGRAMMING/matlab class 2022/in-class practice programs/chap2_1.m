% program 1 initial value from input
F_t=input('please input the F degree: ');
C_t=(F_t-32)*(5/9);
display(C_t);

% program 2: initial value from input
u_0=input('initial velocity: ');
u_0=150;
t=0:0.5:40;
g=9.81;
% calculate the vertical displacement
S_t=u_0.*t-(g/2)*(t.^2);
plot(t,S_t,'b--o');

% point-wise matrix operation
A1=[ 1 1 ; 2 3];
A2=[ 2 2; 2 1];
B=A1.*A2;

% change the matrix value by using ':' and find
A=floor(6*(rand(4,5)));
B=zeros(size(A));
ind=find(A>3);
B=A;
B(ind)=3;

v1=[ 10 12 14 16 18 20]';
v2=repmat(v1,1,4)

theta1=50:10:80;
theta=repmat(theta1,6,1)
g=9.8;

h=(v2.^2).*(sind(theta).^2)/(2*g);




