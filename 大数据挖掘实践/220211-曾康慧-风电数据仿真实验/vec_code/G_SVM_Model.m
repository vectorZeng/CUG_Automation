function [trainedModel, validationRMSE] = G_SVM_Model(trainingData, responseData)
% [trainedModel, validationRMSE] = trainRegressionModel(trainingData,
% responseData)
% 返回经过训练的回归模型及其 RMSE。以下代码重新创建在回归学习器中训练的模型。您可以使用该生
% 成的代码基于新数据自动训练同一模型，或通过它了解如何以程序化方式训练模型。
%
%  输入:
%      trainingData: 一个与导入 App 中的矩阵具有相同列数和数据类型的矩阵。
%
%      responseData: 一个与导入 App 中的向量具有相同数据类型的向量。responseData 的
%       长度和 trainingData 的行数必须相等。
%
%
%  输出:
%      trainedModel: 一个包含训练的回归模型的结构体。该结构体中具有各种关于所训练模型的
%       信息的字段。
%
%      trainedModel.predictFcn: 一个对新数据进行预测的函数。
%
%      validationRMSE: 表示验证 RMSE 的双精度值。在 App 中，"模型" 窗格显示每个模型
%       的验证 RMSE。
%
% 使用该代码基于新数据来训练模型。要重新训练模型，请使用原始数据或新数据作为输入参数
% trainingData 和 responseData 从命令行调用该函数。
%
% 例如，要重新训练基于原始数据集 T 和响应 Y 训练的回归模型，请输入:
%   [trainedModel, validationRMSE] = trainRegressionModel(T, Y)
%
% 要使用返回的 "trainedModel" 对新数据 T2 进行预测，请使用
%   yfit = trainedModel.predictFcn(T2)
%
% T2 必须是仅包含用于训练的预测变量列的矩阵。有关详细信息，请输入:
%   trainedModel.HowToPredict

% 由 MATLAB 于 2024-06-14 18:48:59 自动生成


% 提取预测变量和响应
% 以下代码将数据处理为合适的形状以训练模型。
%
% 将输入转换为表
inputTable = array2table(trainingData, 'VariableNames', {'column_1', 'column_2', 'column_3'});

predictorNames = {'column_1', 'column_2', 'column_3'};
predictors = inputTable(:, predictorNames);
response = responseData;
isCategoricalPredictor = [false, false, false];

% 训练回归模型
% 以下代码指定所有模型选项并训练模型。
responseScale = iqr(response);
if ~isfinite(responseScale) || responseScale == 0.0
    responseScale = 1.0;
end
boxConstraint = responseScale/1.349;
epsilon = responseScale/13.49;
regressionSVM = fitrsvm(...
    predictors, ...
    response, ...
    'KernelFunction', 'gaussian', ...
    'PolynomialOrder', [], ...
    'KernelScale', 0.43, ...
    'BoxConstraint', boxConstraint, ...
    'Epsilon', epsilon, ...
    'Standardize', true);

% 使用 predict 函数创建结果结构体
predictorExtractionFcn = @(x) array2table(x, 'VariableNames', predictorNames);
svmPredictFcn = @(x) predict(regressionSVM, x);
trainedModel.predictFcn = @(x) svmPredictFcn(predictorExtractionFcn(x));

% 向结果结构体中添加字段
trainedModel.RegressionSVM = regressionSVM;
trainedModel.About = '此结构体是从回归学习器 R2023b 导出的训练模型。';
trainedModel.HowToPredict = sprintf('要对新预测变量列矩阵 X 进行预测，请使用: \n yfit = c.predictFcn(X) \n将 ''c'' 替换为作为此结构体的变量的名称，例如 ''trainedModel''。\n \nX 必须包含正好 3 个列，因为此模型是使用 3 个预测变量进行训练的。\nX 必须仅包含与训练数据具有完全相同的顺序和格式的\n预测变量列。不要包含响应列或未导入 App 的任何列。\n \n有关详细信息，请参阅 <a href="matlab:helpview(fullfile(docroot, ''stats'', ''stats.map''), ''appregression_exportmodeltoworkspace'')">How to predict using an exported model</a>。');

% 提取预测变量和响应
% 以下代码将数据处理为合适的形状以训练模型。
%
% 将输入转换为表
inputTable = array2table(trainingData, 'VariableNames', {'column_1', 'column_2', 'column_3'});

predictorNames = {'column_1', 'column_2', 'column_3'};
predictors = inputTable(:, predictorNames);
response = responseData;
isCategoricalPredictor = [false, false, false];

% 执行交叉验证
KFolds = 5;
cvp = cvpartition(size(response, 1), 'KFold', KFolds);
% 将预测初始化为适当的大小
validationPredictions = response;
for fold = 1:KFolds
    trainingPredictors = predictors(cvp.training(fold), :);
    trainingResponse = response(cvp.training(fold), :);
    foldIsCategoricalPredictor = isCategoricalPredictor;

    % 训练回归模型
    % 以下代码指定所有模型选项并训练模型。
    responseScale = iqr(trainingResponse);
    if ~isfinite(responseScale) || responseScale == 0.0
        responseScale = 1.0;
    end
    boxConstraint = responseScale/1.349;
    epsilon = responseScale/13.49;
    regressionSVM = fitrsvm(...
        trainingPredictors, ...
        trainingResponse, ...
        'KernelFunction', 'gaussian', ...
        'PolynomialOrder', [], ...
        'KernelScale', 0.43, ...
        'BoxConstraint', boxConstraint, ...
        'Epsilon', epsilon, ...
        'Standardize', true);

    % 使用 predict 函数创建结果结构体
    svmPredictFcn = @(x) predict(regressionSVM, x);
    validationPredictFcn = @(x) svmPredictFcn(x);

    % 向结果结构体中添加字段

    % 计算验证预测
    validationPredictors = predictors(cvp.test(fold), :);
    foldPredictions = validationPredictFcn(validationPredictors);

    % 按原始顺序存储预测
    validationPredictions(cvp.test(fold), :) = foldPredictions;
end

% 计算验证 RMSE
isNotMissing = ~isnan(validationPredictions) & ~isnan(response);
validationRMSE = sqrt(nansum(( validationPredictions - response ).^2) / numel(response(isNotMissing) ));
