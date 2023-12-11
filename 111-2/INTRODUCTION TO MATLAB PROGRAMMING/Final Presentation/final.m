load('mnist.mat')
trainData = training.images ;
trainLabel = training.labels ;
testData = test.images ;
testLabel = test.labels ;

trainData = reshape(trainData, 28, 28, 1, []);
trainLabel = categorical(trainLabel);
testData = reshape(testData, 28, 28, 1, []);
testLabel = categorical(testLabel);

trainDatastore = augmentedImageDatastore([28 28 1], trainData, trainLabel, 'DataAugmentation', 'none');
testDatastore = augmentedImageDatastore([28 28 1], testData, testLabel, 'DataAugmentation', 'none');

rng('default');
 
% Define the layers for the convolutional neural network
layers = [
    imageInputLayer([28 28 1])
    convolution2dLayer(3, 8, 'Padding', 'same')
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, 'Stride', 2)
    convolution2dLayer(3, 16, 'Padding', 'same')
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, 'Stride', 2)
    convolution2dLayer(3, 32, 'Padding', 'same')
    batchNormalizationLayer
    reluLayer
    fullyConnectedLayer(10)
    softmaxLayer
    classificationLayer];

% Specify the training options
options = trainingOptions('sgdm', ...
    'MaxEpochs', 10, ...
    'ValidationData', testDatastore, ...
    'ValidationFrequency', 30, ...
    'MiniBatchSize', 1024, ...
    'Verbose', false, ...
    'Plots', 'training-progress', ...
    'ExecutionEnvironment', 'gpu');

% Train the network
net = trainNetwork(trainData, trainLabel, layers, options);

% Test the network on the testing dataset
YPred = classify(net, testData);
YTest = testLabel;

% Calculate the accuracy
accuracy = sum(YPred == YTest)/numel(YTest)