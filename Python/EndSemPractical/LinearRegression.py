import matplotlib.pyplot as plt
from scipy import stats

x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
y = [99,86,87,88,111,86,103,87,94,78,77,85,86]

slope, intercept, r, p, std_err = stats.linregress(x, y)

def func(x):
    return slope*x + intercept

myModel = list(map(func, x))

plt.scatter(x, y)
plt.plot(x, myModel)
plt.show()