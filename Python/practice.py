# import pandas as pd
# import matplotlib.pyplot as plt
# import os

# fs = os.path.join(os.getcwd(), 'Python', 'data.csv')
# # print(fs)

# df = pd.read_csv(fs)

# print(df.head())

# # df['Duration'].plot(kind = 'hist')

# # plt.show()

# print(df.info())
# print(df.describe())

# import the pandas library
# import pandas as pd
# import numpy as np
# data = {'Name': ['Parker', 'Smith', 'John', 'William'],
#         'Percentage': [82, 98, 91, 87],
#         'Course': ['B.Sc', 'B.Ed', 'M.Phill', 'BA']}
# df = pd.DataFrame(data)

# grouped = df.groupby('Course')
# print(grouped['Percentage'].mean())


import pandas as pd
import os

fs = os.path.join(os.getcwd(), 'Python', 'data.csv')
# print(fs)

df = pd.read_csv('./Python/GeoTags.csv')

# print(df.head(10).groupby('Continent').max('Population'))
# print(df[['Continent', 'Population']].head().groupby('Continent').max('Population'))
# print(df.loc[:,['Continent', 'Population']].head().groupby('Continent').max('Population'))

mydf = df.dropna().groupby('Continent').mean('Population')

print(mydf.sort_values(by='Continent', ascending = False).to_string())

