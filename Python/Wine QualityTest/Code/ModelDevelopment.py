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
# display new dataframe
# print(df.head())

df['best quality'] = [1 if x > 5 else 0 for x in df.quality]
print(df.head(10))

# See proportion of good vs bad wines
# print(df['best quality'].value_counts())

# features = df.drop(['quality', 'best quality'], axis=1)
features = df.drop(['quality', 'best quality', 'type_white'], axis=1)
target = df['best quality']

xtrain, xtest, ytrain, ytest = train_test_split(
	features, target, test_size=0.2, random_state=40)

# print(xtrain.shape, xtest.shape)

norm = MinMaxScaler()
xtrain = norm.fit_transform(xtrain)
xtest = norm.transform(xtest)

print(xtrain)

