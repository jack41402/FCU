A=[1 4 2;
   2 4 100;
   7 9 7;
   3 pi 42];
%(a)
B=(A')
%(b)
D=A([1:2,4],:)
%(c)
x=B(3,:)
%(d)
x_sum=sum(x)
%(e)
e=A(2,:).*B(:,3)