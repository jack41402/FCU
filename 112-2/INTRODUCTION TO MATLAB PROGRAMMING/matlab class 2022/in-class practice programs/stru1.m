%% generate a structure for the social science
clear all;
S.name = 'Ed Plum';
S.score = 83;
S.grade = 'B+';
S(2).name = 'Toni Miller';
S(2).score = 91;
S(2).grade = 'A-';
% or an entire element can be added with a single statement.
S(3) = struct('name','Jerry Garcia','score',70,'grade','C');
%% generate another class
T.name = 'Ed Plum';
T.score = [ 83  89];

T(2).name = 'Toni Miller';
T(2).score = 91;

% or an entire element can be added with a single statement.
T(3) = struct('name','Jerry Garcia','score',70);


class(1).name='MATH101';
class(1).student=S;
class(2).name='LAN102';
class(2).student=T;

class(3).name='MATLAB102';
class(3).student=S;

% access the data with field name
class(2).student(2).score
class(3).student(1).name
class(3).student(1)= struct('name','Jerry Garcia','score',70,'grade','C');
class(3).student(1).name

%% Structure Arrays
% Structure arrays contain data in fields that you access by field name.
% For example, store patient records in a structure array.
patient(1).name = 'John Doe';
patient(1).billing = 127.00;
patient(1).test = [79, 75, 73; 180, 178, 177.5; 220, 210, 205];

patient(2).name = 'Ann Lane';
patient(2).billing = 28.50;
patient(2).test = [68, 70, 68; 118, 118, 119; 172, 170, 169];
% Create a bar graph of the test results for each patient.
numPatients = numel(patient);
for p = 1:numPatients
   figure
   bar(patient(p).test)
   title(patient(p).name)
end


%% Cell Arrays
% Cell arrays contain data in cells that you access by numeric indexing.
% Common applications of cell arrays include storing separate pieces 
% of text and storing heterogeneous data from spreadsheets.
% For example, store temperature data for three cities over time in a cell array.

temperature(1,:) = {'01-Jan-2010', [45, 49, 0]};
temperature(2,:) = {'03-Apr-2010', [54, 68, 21]};
temperature(3,:) = {'20-Jun-2010', [72, 85, 53]};
temperature(4,:) = {'15-Sep-2010', [63, 81, 56]};
temperature(5,:) = {'31-Dec-2010', [38, 54, 18]};

% Plot the temperatures for each city by date.
allTemps = cell2mat(temperature(:,2));
dates = datenum(temperature(:,1), 'dd-mmm-yyyy');

plot(dates,allTemps,'--*')
datetick('x','mmm')


A{1,1} = {'This is the first cell.'};
A(1,2) = {[5+j*6 , 4+j*5]};  
A(2,1) = {[1 2 3; 4 5 6; 7 8 9]};
A(2,2) = {{'Tim'; 'Chris'}} 


%% 
clear student		% 清除 student 變數
student(1) = struct('name', 'Banny', 'scores', [85,80,92,78]);
student(2) = struct('name', 'Joey', 'scores', [80,85,90,88]);
student(3) = struct('name', 'Betty', 'scores', [88,82,90,80]);

%% calculate the avg score
allscores=[student.scores];
B=reshape(allscores,4,3)';
avg1=mean(B)

mean(student.scores)








