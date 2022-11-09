from statistics import LinearRegression
import pandas as pd
# creating Dataframe object
df = pd.read_csv('winequalityN.csv')
# print(df.head())
# print(df.info())
# print(df.describe())


import matplotlib.pyplot as plt

# df.hist(bins=25,figsize=(10,10))
# display histogram
# plt.show()

# plt.figure(figsize=[10,6])
# # plot bar graph
# plt.bar(df['quality'],df['alcohol'],color='red')
# # label x-axis
# plt.xlabel('quality')
# #label y-axis
# plt.ylabel('alcohol')

# plt.show()

import seaborn as sb
import warnings
warnings.filterwarnings('ignore')
# ploting heatmap
# plt.figure(figsize=[19,10],facecolor='blue')
# sb.heatmap(df.corr(),annot=True)
# plt.show()

# for a in range(len(df.corr().columns)):
#     for b in range(a):
#         if abs(df.corr().iloc[a,b]) >0.7:
#             name = df.corr().columns[a]
#             print(name)

new_df=df.drop('total sulfur dioxide',axis=1)

new_df.isnull().sum()

new_df.update(new_df.fillna(new_df.mean()))

# catogerical vars 
next_df = pd.get_dummies(new_df,drop_first=True)
# display new dataframe
# print(next_df.head(10))

next_df['best quality'] = [ 1 if x>=7 else 0 for x in df.quality] 
# print(next_df)

from sklearn.model_selection import train_test_split
x = next_df.drop(['quality', 'best quality'], axis=1)
y = next_df['best quality']

x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=40)

#importing module
from sklearn.preprocessing import MinMaxScaler
# creating normalization object 
norm = MinMaxScaler()
# fit data
norm_fit = norm.fit(x_train)
new_xtrain = norm_fit.transform(x_train)
new_xtest = norm_fit.transform(x_test)
# display values
# print(new_xtrain)

# importing modules
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.metrics import mean_squared_error
#creating RandomForestClassifier constructor
rnd = RandomForestClassifier()
# model = LogisticRegression()
# model.fit(new_xtrain, y_train)
# fit data
fit_rnd = rnd.fit(new_xtrain,y_train)
# predicting score
x_predict = list(rnd.predict(new_xtest))
y_predict = rnd.predict(new_xtest)
# y_predict = rnd.predict(y_test)
rnd_score = rnd.score(new_xtest,y_test)
print('score of model is : ',rnd_score)
# display error rate
print('calculating the error')
# calculating mean squared error
rnd_MSE = mean_squared_error(y_test,y_predict)
# calculating root mean squared error
rnd_RMSE = np.sqrt(rnd_MSE)
# display MSE
print('mean squared error is : ',rnd_MSE)
# display RMSE
print('root mean squared error is : ',rnd_RMSE)
print(classification_report(x_predict,y_test))

# x_predict = list(rnd.predict(x_test))
predicted_df = {'predicted_values': x_predict, 'original_values': y_test}
#creating new dataframe
print(pd.DataFrame(predicted_df).head(20))