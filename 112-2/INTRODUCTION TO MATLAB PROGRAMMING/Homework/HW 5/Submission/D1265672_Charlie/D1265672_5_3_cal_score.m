load('score_data.mat');

avg = mean(score, 1);

gpa = zeros(1, N); 

for student = 1:N
    if avg(student) >= 90
        gpa(student) = 4.3;
    elseif avg(student) >= 85
        gpa(student) = 4.0;
    elseif avg(student) >= 80
        gpa(student) = 3.7;
    elseif avg(student) >= 77
        gpa(student) = 3.3;
    elseif avg(student) >= 73
        gpa(student) = 3.0;
    elseif avg(student) >= 70
        gpa(student) = 2.7;
    elseif avg(student) >= 67
        gpa(student) = 2.3;
    elseif avg(student) >= 63
        gpa(student) = 2.0;
    elseif avg(student) >= 60
        gpa(student) = 1.7;
    elseif avg(student) >= 40
        gpa(student) = 1.0;
    elseif avg(student) >= 1
        gpa(student) = 0.0;
    else
        gpa(student) = 0.0;
    end
end

save('score_data_2.mat', 'score', 'avg', 'gpa', 'N');