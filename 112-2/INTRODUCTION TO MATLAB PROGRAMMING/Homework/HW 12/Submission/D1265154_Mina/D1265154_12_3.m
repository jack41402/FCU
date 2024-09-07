time = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4];
voltage = [100, 62, 38, 21, 13, 7, 4, 2, 3];
V0 = 100;
exp_decay = @(k, t) V0 * exp(-k * t);
objective_function = @(k) sum((exp_decay(k, time) - voltage).^2);
k_opt = fminbnd(objective_function, 0, 1);
fitted_voltage = exp_decay(k_opt, time);
n = 8;
voltage_at_n = exp_decay(k_opt, n);
figure;
hold on;
plot(time, voltage, 'o', 'MarkerEdgeColor', 'b', 'MarkerFaceColor', 'none'); 
plot(time, voltage, 'r-'); 
hold off;
xlim([0 4]);
ylim([0 120]);

