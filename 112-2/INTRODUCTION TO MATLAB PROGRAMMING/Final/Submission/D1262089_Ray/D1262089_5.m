clear all
clc
% Read the Excel file
data = readtable('test_score1.xls');
table = table2struct(data);
% Calculate 
m_mid=mean([table.x_____1]);
m_final=mean([table.x_____2]);
s_mid=std([table.x_____1]);
s_final=std([table.x_____2]);

fprintf('Means of mid-term scores: %.2f\n',m_mid);
fprintf('Standard deviation of mid-term scores: %.2f\n',s_mid);
fprintf('Means of final scores: %.2f\n',m_final);
fprintf('Standard deviation of final scores: %.2f\n',s_final);

% Filter the data
filtered_final_scores = data.x_____2(data.x_____2 >= 60 & data.x_____2 <= 100);
edges = 60:5:100;  % step5

% Plot the distribution of x_____2 using histogram
figure;
histogram(filtered_final_scores, edges);


