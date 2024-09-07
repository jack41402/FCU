term = 100;

pi_approximate = 0;

for n = 0:term
    pi_approximate = pi_approximate + (-1)^n / (2*n + 1);
end

pi_approximate = 4 * pi_approximate;

disp(['a = ', num2str(pi_approximate)]);

%b
term = 100zz; 

pi_approximate = 0;


for n = 0:term
    pi_approximate = pi_approximate + 1 / ((4 * n + 1) * (4 * n + 3));
end

pi_approximate = 8 * pi_approximate;

disp(['b = ', num2str(pi_approximate)]);

%c
pi_approximate = 0;
pi_approximate = pi_approximate + 6 * atan(1/8);
pi_approximate = pi_approximate + 2 * atan(1/57);
pi_approximate = pi_approximate + atan(1/239);
pi_approximate = 4 * pi_approximate;

disp(['c = ', num2str(pi_approximate)]);
