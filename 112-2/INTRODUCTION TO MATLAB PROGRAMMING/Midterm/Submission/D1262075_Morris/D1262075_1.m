%1_a
theta = (-pi/2):(pi/20):(pi/2);
t = 0:0.2:4;
a = 5;
b = 2;
ans1 = [exp(-0.2.*t).*sin(b.*theta)+log(t+1)].*cos(2.*theta).*cos(2.*theta);
disp(ans1);
%1_b
ans2 = [sin(a.*t).^(-1)+log(t.^2+2.*t+1)].*tan(theta./2);
disp(ans2);
%1_c
ans3 = (exp(t)+sin(theta))./b;
disp(ans3);
