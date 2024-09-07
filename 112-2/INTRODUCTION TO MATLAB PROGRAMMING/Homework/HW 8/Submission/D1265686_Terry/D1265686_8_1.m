w = (1:4:100000000);
y = zeros(1,100000);

for i=1:100000

    y(i) = 4 .* ( 1./w(i) - 1./(w(i)+2) ) ;

end

a = sum(y)


w = (1:4:1000000000);
y = zeros(1,1000000);

for i=1:1000000

    y(i) = 8 .* (1 ./ (w(i) .* (w(i)+2) ));

end

b = sum(y)


e = (1:4:1000000);
u = zeros(1,10000);

k = 1/8;
for i=1:10000
    u(i) = ( k.^e(i) ./ e(i) ) - (k.^ (e(i)+2) ./ (e(i)+2) );
end
a1 = sum(u);

u = zeros(size(u));

k = 1/57;
for i=1:10000
    u(i) = ( k.^e(i) ./ e(i) ) - (k.^ (e(i)+2) ./ (e(i)+2) );
end
a2 = sum(u);

u = zeros(size(u));

k = 1/239;
for i=1:10000
    u(i) = ( k.^e(i) ./ e(i) ) - (k.^ (e(i)+2) ./ (e(i)+2) );
end
a3 = sum(u);

c = 4 .* (6.*a1 + 2.*a2 + a3)
