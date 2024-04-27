v = 60 ;
rad = deg2rad(50) ;
x = @(t) v*cos(rad).*t ;
y = @(t) v*sin(rad).*t - 0.5*9.81.*t.^2 ;
t = 0 ;
fprintf("\ttime      x           y\n") ;

while y(t)>=0
    time_str = sprintf('%.1f', t);
    hdist_str = sprintf('%3.4f', x(t));
    vdist_str = sprintf('%3.4f', y(t));
    fprintf("\t%s\t%+10s\t%+10s\n", time_str, hdist_str, vdist_str)
    % disp(['    ', time_str, '    ', hdist_str, '    ', vdist_str]); % Concatenate the strings with proper spacing
    % fprintf("\t%.1f   \t%3.4f   %3.4f\n", t, x(t), y(t))
    % disp([t x(t) y(t)])
    t = t + 0.5 ;
end

