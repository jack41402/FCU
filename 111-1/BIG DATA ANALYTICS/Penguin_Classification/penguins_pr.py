import pandas as pd
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
import seaborn as sns
from sklearn.metrics import precision_score, recall_score
from sklearn import tree
import matplotlib.pyplot as plt
max_depth = 3

def species_fix(input):
    if 'Adelie' in input:
        return 'Adelie'
    if 'Chinstrap' in input:
        return 'Chinstrap'
    if 'Gentoo' in input:
        return 'Gentoo'


penguins_df = pd.read_csv('./penguins_lter.csv')

# print(penguins_df.columns)

cols = ['Species', 'Island', 'Culmen Length (mm)', 'Culmen Depth (mm)', 'Flipper Length (mm)', 'Body Mass (g)', 'Sex']
rename_dict = {'Culmen Length (mm)': 'Culmen_Length',
               'Culmen Depth (mm)': 'Culmen_Depth',
               'Flipper Length (mm)': 'Flipper_Length',
               'Body Mass (g)': 'Body_Mass'}


df_tmp = penguins_df[cols].rename(columns=rename_dict)
df_tmp['Species'] = df_tmp['Species'].apply(species_fix)
df_tmp = df_tmp.dropna()
df_tmp = df_tmp.reindex()
df_tmp = pd.get_dummies(df_tmp, columns=['Sex']).drop(['Island', 'Sex_.'], axis=1)

df_tmp.to_csv('./penguins_sample_calssification.csv', index=False)
data = pd.read_csv('./penguins_sample_calssification.csv')
x_data = data.drop(['Species'], axis=1)
y_data = data['Species']

x_train, x_test, y_train, y_test = train_test_split(x_data, y_data, test_size=0.2)

clf = tree.DecisionTreeClassifier(max_depth=max_depth)
clf.fit(x_train, y_train)
target_names = ['Adelie', 'Chinstrap', 'Gentoo']
feature_names = x_data.columns
y_pred = clf.predict(x_test)
print('Test Data Accuracy: ', accuracy_score(y_pred, y_test))
print('Precision : ', precision_score(y_test,y_pred,labels = 'Adelie',average=None)[0])
print('recall :',recall_score(y_test,y_pred,labels='Adelie',average = None)[0])
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
result = confusion_matrix(y_test,y_pred)
tp = result[0][0]
print('tp :',tp)
fp = result[1][0] + result[2][0]
print('fp :',fp)
print('Precision :',tp / (tp + fp))
fn = result[0][1] + result[0][2]
print('fn :',fn)
print('recall :',tp/ (tp + fn))
print(result)