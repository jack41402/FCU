% (1) Read the table from the provided Excel file
score_table = readtable("test_score1.xls", 'VariableNamingRule', 'preserve');

% (2) Calculate the average scores for specific columns (4:6 for 平時考核, 期中考試, 期末考試)
average_regular_assessment = mean(score_table{:, 4}, 'omitnan');
average_midterm_exam = mean(score_table{:, 5}, 'omitnan');
average_final_exam = mean(score_table{:, 6}, 'omitnan');

% Create the new average row
average_row = {"29", "Average score", NaN, average_regular_assessment, average_midterm_exam, average_final_exam, NaN, NaN, NaN};

% (3) Add the average row to the table
score_table = [score_table; average_row];

% Define the new column titles
new_column_titles = {'順序', '學號', '姓名', '平時考核', '期中考試', '期末考試', '平時等第', '期中等第', '期末等第'};

% Rename the columns
score_table.Properties.VariableNames = new_column_titles;

% (4) Write the updated table to a new Excel file
writetable(score_table, "answer.xlsx");
