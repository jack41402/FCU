cal_pi_a = @(x) 4*( ((-1)^(x-1)) * 1 / (1 + (x-1) * 2));
a=0;
for x = 1:100000
    a = a + cal_pi_a(x);
end
a

cal_pi_b = @(x) 8*( 1 / (( 1 + 4 * (x-1) ) * ( 3 + 4  *(x-1) )) );
b=0;
for x = 1:12000
    b = b + cal_pi_b(x);
end
b


cal_pi_c = @(x) 4*(6*(((-1)^(x-1))*((1/8)^(1+2*(x-1)))/(1+2*(x-1)))+2*(((-1)^(x-1))*((1/57)^(1+2*(x-1)))/(1+2*(x-1)))+(((-1)^(x-1))*((1/239)^(1+2*(x-1)))/(1+2*(x-1))));
c=0;
for x = 1:1200
    c = c +cal_pi_c(x);
end
c