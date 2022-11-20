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

print(df.head())

print(df.info())

print(df.describe().T)

