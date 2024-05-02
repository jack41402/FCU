a=[6 2 1;2 5 4;4 3 2;9 7 3]
b=[10 12 13 15;8 7 6 4;12 10 13 9;6 4 11 5]
k='Quarterly costs for materials: %d,%d,%d,%d';
l='Quarterly costs for labor: %d,%d,%d,%d';
m='Quarterly costs for transportation: %d,%d,%d,%d';
n='Total costs for materials: %d'
o='Total costs for labor: %d'
p='Total costs for transportation: %d'
q='The total quarterly costs: %d,%d,%d,%d'
c=sum(a(:,1).*b(:,1))*1000;
d=sum(a(:,1).*b(:,2))*1000;
e=sum(a(:,1).*b(:,3))*1000;
f=sum(a(:,1).*b(:,4))*1000;
fprintf(k,c,d,e,f)
c=sum(a(:,2).*b(:,1))*1000;
d=sum(a(:,2).*b(:,2))*1000;
e=sum(a(:,2).*b(:,3))*1000;
f=sum(a(:,2).*b(:,4))*1000;
fprintf('\n')
fprintf(l,c,d,e,f)
c=sum(a(:,3).*b(:,1))*1000;
d=sum(a(:,3).*b(:,2))*1000;
e=sum(a(:,3).*b(:,3))*1000;
f=sum(a(:,3).*b(:,4))*1000;
fprintf('\n')
fprintf(m,c,d,e,f)
c=sum((a(:,1).*b(:,1))+(a(:,1).*b(:,2))+(a(:,1).*b(:,3))+(a(:,1).*b(:,4)))*1000;
fprintf('\n')
fprintf(n,c)
d=sum((a(:,2).*b(:,1))+(a(:,2).*b(:,2))+(a(:,2).*b(:,3))+(a(:,2).*b(:,4)))*1000;
fprintf('\n')
fprintf(o,d)
e=sum((a(:,3).*b(:,1))+(a(:,3).*b(:,2))+(a(:,3).*b(:,3))+(a(:,3).*b(:,4)))*1000;
fprintf('\n')
fprintf(p,e)
c=sum((a(:,1).*b(:,1))+(a(:,2).*b(:,1))+(a(:,3).*b(:,1)))*1000;
d=sum((a(:,1).*b(:,2))+(a(:,2).*b(:,2))+(a(:,3).*b(:,2)))*1000;
e=sum((a(:,1).*b(:,3))+(a(:,2).*b(:,3))+(a(:,3).*b(:,3)))*1000;
f=sum((a(:,1).*b(:,4))+(a(:,2).*b(:,4))+(a(:,3).*b(:,4)))*1000;
fprintf('\n')
fprintf(q,c,d,e,f)
