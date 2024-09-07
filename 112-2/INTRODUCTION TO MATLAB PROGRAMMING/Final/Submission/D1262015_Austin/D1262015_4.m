clear student
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);
student(4) = struct('name', 'Mary', 'scores', [80,70,92,86]);


scoreMatrix = zeros(4, 4);

for i = 1:4
    scoreMatrix(i, :) = student(i).scores;
end

scoreMatrix
weights = [0.25, 0.25, 0.2, 0.3];


avg = scoreMatrix * weights';
avg'

