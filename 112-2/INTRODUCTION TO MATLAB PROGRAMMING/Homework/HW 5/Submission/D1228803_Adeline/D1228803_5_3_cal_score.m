close all;
clear all;

N = input('Number of students: ');

score = zeros(2, N);
average = zeros(1, N);
gpa = zeros(1, N);

for i = 1:N
    str1 = input('Student name: ', 's');
    eval(['name', int2str(i), '=str1;']);
    score(1, i) = input('Math score: ');
    score(2, i) = input('English score: ');
    average(i) = (score(1, i) + score(2, i)) / 2;
    
    % Call calculateGPA function to calculate GPA for each student
    fprintf('Calculating GPA for %s:\n', str1);
    gpa(i) = calculateGPA(score(:,i));
end

for i = 1 : N
    eval(['str1=name', int2str(i), ';']);
    fprintf('The average score of %s is %3.2f\n', str1, average(i));
    fprintf('The GPA of %s is %3.2f\n', str1, gpa(i));
end

save score_data N score;

function GPA = calculateGPA(scores)
    average = mean(scores);

    if average >= 90
        GPA = 4.3;
    elseif average >= 85 && average < 90
        GPA = 4.0;
    elseif average >= 80 && average < 85
        GPA = 3.7;
    elseif average >= 77 && average < 80
        GPA = 3.3;
    elseif average >= 73 && average < 77
        GPA = 3.0;
    elseif average >= 70 && average < 73
        GPA = 2.7;
    elseif average >= 67 && average < 70
        GPA = 2.3;
    elseif average >= 63 && average < 67
        GPA = 2.0;
    elseif average >= 60 && average < 63
        GPA = 1.7;
    elseif average >= 40 && average < 60
        GPA = 1.0;
    else
        GPA = 0.0;
    end

    fprintf('Average score: %.2f\n', average);
    fprintf('GPA: %.2f\n', GPA);
end
