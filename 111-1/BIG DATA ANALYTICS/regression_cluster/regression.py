import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error
from sklearn import tree
from sklearn.linear_model import LinearRegression
import seaborn as sns

# 是否用決策樹，否的話用線性迴歸
decision_tree = True

# 讀取資料
boston_data = datasets.load_boston()
df_data = pd.DataFrame(boston_data.data, columns=boston_data.feature_names)
df_data['MEDV'] = boston_data['target']

print(boston_data.DESCR)

plt.subplots(figsize=(10, 8))
sns.heatmap(df_data.corr(), annot=True)

# 切分資料
x_data = boston_data.data
y_data = boston_data.target

x_train, x_test, y_train, y_test = train_test_split(x_data, y_data, test_size=0.2)

# 模型
if decision_tree:
    reg = tree.DecisionTreeRegressor(max_depth=4)
else:
    reg = LinearRegression()
reg.fit(x_train, y_train)

y_pred = reg.predict(x_test)

# 指標
print('RMSE: ', mean_squared_error(y_test, y_pred, squared=False))
print('MAE: ', mean_absolute_error(y_test, y_pred))

# 畫圖
plt.subplots(figsize=(10, 8))
plt.xlabel('\nActual Price', fontsize=16)
plt.ylabel('Predicted Price', fontsize=16)
plt.plot([-50, 100], [-50, 100])  # 1:1 line
plt.scatter(y_test, y_pred)
plt.xlim(0, 60)
plt.ylim(0, 60)

if decision_tree:
    plt.figure(figsize=(19, 6))
    tree.plot_tree(reg, feature_names=boston_data.feature_names, filled=True, fontsize=6)
    print(tree.export_text(reg, feature_names=list(boston_data.feature_names)))
plt.show()
