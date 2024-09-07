C=readcell("test_score1.xls");
data.Properties.VariableNames = {'Index', 'ID', 'Name', 'RegularAssessment', 'MidtermExam', 'FinalExam', 'RegularGrade', 'MidtermGrade', 'FinalGrade'}; % Rename the variable names in the table
avgRegularAssessment = mean(data.RegularAssessment);
avgMidtermExam = mean(data.MidtermExam);
avgFinalExam = mean(data.FinalExam)
devMidtermExam=std(data.MidtermExam);
devFinalExam=std(data.FinalExam);
fprintf('Mean of mid-term scores: %.2f\n',avgMidtermExam);
fprintf('Standard deviation of mid-term scores: %.2f\n',devMidtermExam);
fprintf('Mean of final scores: %.2f\n',avgFinalExam);
fprintf('Standard deviation of final scores: %.2f',devFinalExam);
histogram(data.FinalExam,20,'BinWidth',5,'BinLimits',[60,100])