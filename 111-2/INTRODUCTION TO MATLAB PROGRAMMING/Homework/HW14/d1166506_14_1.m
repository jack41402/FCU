digitDatasetPath = fullfile(matlabroot,'toolbox','nnet','nndemos', 'nndatasets','DigitDataset');
% fullfile function : Builds a full file specification from the specified folder and file names. 

 imds = imageDatastore(digitDatasetPath, ...
	 'IncludeSubfolders',true, ...
	 'LabelSource','foldernames');
% imageDatastore : to manage a collection of image files
numTrainFiles = 750;
% separate the images to 750images in one set to categorize the images
[imdsTrain,imdsValidation] = splitEachLabel(imds,numTrainFiles,'randomized');
%splits the image datastore into two new datasotres for training and validation.
inputSize = [28 28 1]; %28by28by1 pixels 
numClasses = 10;
 layers = [ imageInputLayer(inputSize) 
	convolution2dLayer(5,20) 
	batchNormalizationLayer
	 reluLayer 
	fullyConnectedLayer(numClasses) 
	softmaxLayer
	 classificationLayer];
options = trainingOptions('sgdm', ...
	 'MaxEpochs',4, ...
	 'ValidationData',imdsValidation, ...
	 'ValidationFrequency',30, ...
	 'Verbose',false, ...
	 'Plots','training-progress');
 net = trainNetwork(imdsTrain,layers,options);
YPred = classify(net,imdsValidation);
 YValidation = imdsValidation.Labels;
 accuracy = mean(YPred == YValidation)

