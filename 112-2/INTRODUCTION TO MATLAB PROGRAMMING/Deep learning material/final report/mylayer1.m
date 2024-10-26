layers = [
    imageInputLayer([32 32 3],'Name','input')
    
    convolution2dLayer(5,6,'Name','conv_1')
    batchNormalizationLayer('Name','BN_1')
    reluLayer('Name','relu_1')
    maxPooling2dLayer(2,'Stride',2,'Name','pool_1')
    
    convolution2dLayer(5,16,'Name','conv_2')
    batchNormalizationLayer('Name','BN_2')
    reluLayer('Name','relu_2')
    maxPooling2dLayer(2,'Stride',2,'Name','pool_2')
    
    fullyConnectedLayer(400,'Name','fc_3')
    fullyConnectedLayer(10,'Name','fc_4')
    softmaxLayer('Name','softmax')
    classificationLayer('Name','classOutput')];

layer1=layerGraph(layers);
plot(layer1)

analyzeNetwork(layer1)
