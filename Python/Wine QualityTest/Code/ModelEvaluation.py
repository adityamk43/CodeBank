from turtle import color
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn import metrics
from sklearn.svm import SVC
from xgboost import XGBClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier

import warnings
warnings.filterwarnings('ignore')
pd.options.display.max_columns = None

# df = pd.read_csv('winequality-red.csv')
# df = pd.read_csv('winequality-white.csv')
df = pd.read_csv('winequalityN.csv')


for col in df.columns:
    if df[col].isnull().sum() > 0:
        df[col] = df[col].fillna(df[col].mean())

df = df.drop('total sulfur dioxide', axis=1)

df['best quality'] = [1 if x > 5 else 0 for x in df.quality]

# catogerical vars 
df = pd.get_dummies(df,drop_first=True)

df['best quality'] = [1 if x > 5 else 0 for x in df.quality]

# features = df.drop(['quality', 'best quality'], axis=1)
features = df.drop(['quality', 'best quality', 'type_white'], axis=1)
target = df['best quality']

xtrain, xtest, ytrain, ytest = train_test_split(
	features, target, test_size=0.2, random_state=40)

norm = MinMaxScaler()
xtrain = norm.fit_transform(xtrain)
xtest = norm.transform(xtest)

models = [LogisticRegression(), XGBClassifier(), SVC(kernel='rbf'), RandomForestClassifier()]

for i in range(4):
	models[i].fit(xtrain, ytrain)

	print(f'{models[i]} : ')
	print('Score of the Model is : ', models[i].score(xtest,ytest))
	print('Training Accuracy : ', metrics.roc_auc_score(ytrain, models[i].predict(xtrain)))
	print('Validation Accuracy : ', metrics.roc_auc_score(
		ytest, models[i].predict(xtest)))
	print()
	

# For Comparing different datasets accuracy of predictions
# for i in range(4):
# 	models[i].fit(xtrain, ytrain)

# 	print(f'{models[i]} : ')
# 	print('Score of the Model is : ', models[i].score(xtest,ytest))
# 	print('Training Accuracy : ', metrics.roc_auc_score(ytrain, models[i].predict(xtrain)))
# 	print('Validation Accuracy : ', metrics.roc_auc_score(
# 		ytest, models[i].predict(xtest)))
# 	xpred = models[i].predict(xtest)
# 	print()
# 	print("Classification Report:")
# 	print(metrics.classification_report(ytest, xpred))
# 	print('....................................')
# 	print()
	

metrics.plot_confusion_matrix(models[3], xtest, ytest)
plt.show()

xpred = models[3].predict(xtest)
ypred = models[1].predict(ytest)

# predicting score
score = models[3].score(xtest,ytest)
print('score of model is : ', score)
print('....................................')
print(metrics.classification_report(ytest, xpred))

# Using Logistic Regression
feat_importances = pd.Series(models[1].feature_importances_, index=features.columns)
feat_importances.nlargest(25).plot(kind='barh',figsize=(10,10), color = 'purple')
plt.show()

# Using Random Forest
feat_importances = pd.Series(models[3].feature_importances_, index=features.columns)
feat_importances.nlargest(25).plot(kind='barh',figsize=(10,10), color = 'purple')
plt.show()

# Filtering df for only good quality
df_temp = df[df['best quality']==1]
print(df_temp.describe())
# Filtering df for only bad quality
df_temp2 = df[df['best quality']==0]
print(df_temp2.describe())

