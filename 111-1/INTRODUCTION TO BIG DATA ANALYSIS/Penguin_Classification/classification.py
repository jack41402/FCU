import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.metrics import recall_score
from sklearn import tree
import seaborn as sns
from xgboost import XGBClassifier

max_depth = 3

# 下面可以不要動

# 讀取資料
iris = datasets.load_iris()

# 把變數跟目標變數讀進來
x_data = iris.data
y_data = iris.target

# 如果習慣用pandas的可以使用df來看資料
df = pd.DataFrame(iris["data"], columns=iris["feature_names"])
df["target"] = iris["target"]
# print(df)

# label
target_names = iris.target_names
feature_names = iris.feature_names

# 分割資料
x_train, x_test, y_train, y_test = train_test_split(x_data, y_data, test_size=0.2)

clf = tree.DecisionTreeClassifier(max_depth=max_depth)
clf.fit(x_train, y_train)

# Predict Accuracy Score
y_pred = clf.predict(x_test)
print('Test Data Accuracy: ', accuracy_score(y_pred, y_test))

# plot
fig, ax = plt.subplots(figsize=(10, 8))
sns.heatmap(confusion_matrix(y_test, y_pred), annot=True, fmt='d', cmap='Blues', annot_kws={"size": 20})
ax.set_title('Confusion Matrix', fontsize=24)
ax.set_xlabel('\nPredicted Values', fontsize=16)
ax.set_ylabel('Actual Values\n', fontsize=16)

ax.xaxis.set_ticklabels(target_names, fontsize=16)
ax.yaxis.set_ticklabels(target_names, fontsize=16)

plt.figure(figsize=(10, 8))
tree.plot_tree(clf, feature_names=feature_names, class_names=target_names, filled=True)
plt.show()
