import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn import cluster
import seaborn as sns

n_clusters = 3

# 讀取資料
iris = datasets.load_iris()

# 把變數跟目標變數讀進來
x_data = iris.data
y_data = iris.target

# 如果習慣用pandas的可以使用df來看資料
df = pd.DataFrame(iris["data"], columns=iris["feature_names"])
df["target"] = iris["target"]
# print(df)

k_means = cluster.KMeans(n_clusters=n_clusters)
kmeans_fit = k_means.fit(x_data)
cluster_labels = kmeans_fit.labels_
print(cluster_labels)
print(y_data)


fig, ax = plt.subplots(figsize=(10, 8))
sns.heatmap(confusion_matrix(y_data, cluster_labels), annot=True, fmt='d', cmap='Blues', annot_kws={"size": 20})
ax.set_title('Confusion Matrix', fontsize=24)
ax.set_xlabel('\nPredicted Values', fontsize=16)
ax.set_ylabel('Actual Values', fontsize=16)

ax.yaxis.set_ticklabels(iris.target_names, fontsize=16)

plt.subplots(figsize=(10, 8))
plt.scatter(x_data[cluster_labels == 0, 0], x_data[cluster_labels == 0, 1], s=100, c='red', label='Iris-setosa')
plt.scatter(x_data[cluster_labels == 1, 0], x_data[cluster_labels == 1, 1], s=100, c='blue', label='Iris-versicolour')
plt.scatter(x_data[cluster_labels == 2, 0], x_data[cluster_labels == 2, 1], s=100, c='green', label='Iris-virginica')   #Visualising the clusters - On the first two columns
plt.scatter(k_means.cluster_centers_[:, 0], k_means.cluster_centers_[:, 1], s=100, c='black', label='Centroids')   #plotting the centroids of the clusters
plt.legend()
plt.show()
