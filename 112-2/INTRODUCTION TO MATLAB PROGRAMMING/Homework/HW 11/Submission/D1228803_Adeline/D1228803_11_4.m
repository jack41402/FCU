%ok

bridges(1) = struct('Location', 'Smith St.', 'MaxLoad', 80, 'YearBuilt', 1928, 'DueForMaintenance', 2011);
bridges(2) = struct('Location', 'Hope Ave.', 'MaxLoad', 90, 'YearBuilt', 1950, 'DueForMaintenance', 2013);
bridges(3) = struct('Location', 'Clark St.', 'MaxLoad', 85, 'YearBuilt', 1933, 'DueForMaintenance', 2012);
bridges(4) = struct('Location', 'North Rd.', 'MaxLoad', 100, 'YearBuilt', 1960, 'DueForMaintenance', 2012);

disp('Initial bridges structure array:');
disp(bridges);

for i = 1:length(bridges)
    if strcmp(bridges(i).Location, 'Clark St.')
        bridges(i).DueForMaintenance = 2018;
        break;
    end
end

disp('Bridges structure array after modifying Clark St. maintenance data:');
disp(bridges);

new_bridge = struct('Location', 'Shore Rd.', 'MaxLoad', 85, 'YearBuilt', 1997, 'DueForMaintenance', 2014);
bridges(end + 1) = new_bridge;

disp('Final bridges structure array after adding Shore Rd.:');
disp(bridges);
