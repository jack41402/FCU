bridge = struct('Location', {'Smith St.', 'Hope Ave.', 'Clark St.', 'North Rd.'}, 'MaxLoad', {80, 90, 85, 100}, 'YearBuilt', {1928, 1950, 1933, 1960},'DueForMaintenance', {2011, 2013, 2012, 2012});
idx = find(strcmp({bridge.Location}, 'Clark St.'));
bridge(idx).DueForMaintenance = 2018;
new_bridge = struct('Location', 'Shore Rd.', 'MaxLoad', 85, 'YearBuilt', 1997, 'DueForMaintenance', 2014);
bridge(end+1) = new_bridge;