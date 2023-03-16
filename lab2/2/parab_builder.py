import matplotlib.pyplot as plt
import numpy as np

x = []
y = []

filename = input("Enter filename: ")

with open(filename, 'r') as f:
    st = f.readline()
    while st:
        x_v, y_v = map(float, st.split()) 
        x.append(x_v)
        y.append(y_v)
        st = f.readline()

x = np.array(x)
y = np.array(y)

def par_mnk(x, y):
    m = x.shape[0]
    x1 = np.sum(x*x)/m
    xx = np.sum(x**4)/m
    xy = np.sum(y*x**2)/m
    y1 = np.sum(y)/m

    D = xx - x1**2
    alpha = (xy - y1*x1)/D
    beta = (y1*xx - x1*xy)/D
    return alpha, beta

def par_mnk_no_b(x, y):
    return np.sum(y*x**2)/np.sum(x**4)

#a, b = par_mnk(x, y)
b = 0
a = par_mnk_no_b(x, y)


X = np.linspace(min(x),max(x),10000)
fig, ax = plt.subplots()

ax.scatter(x, y, 5, 'b')
ax.plot(X, a*X*X + b, '-r')

plt.title("Swaps(N)")
plt.grid(visible=True)
plt.xlabel("N")
plt.ylabel("Swaps")
plt.show()
