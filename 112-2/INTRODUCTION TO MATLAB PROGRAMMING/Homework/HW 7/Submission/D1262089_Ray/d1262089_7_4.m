x=input('x:');
y=input('y:');
swop(x,y)
function swop(x,y)
temp=y;
y=x;
x=temp;
fprintf("(x,y)=(%d %d)",x,y)
end