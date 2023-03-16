import matplotlib.pyplot as plt
import numpy as np

CLR = ['-r', '-g', '-y']
CLR2 = ['r', 'g', 'y']
fig, ax = plt.subplots()
for i in range(3):

    x = []
    y = []


    filename = "data_time" + str(i+1) + ".txt"
    with open(filename, 'r') as f:
        st = f.readline()
        while st:
            x_v, y_v = map(float, st.split())
            if y_v > 1:
                x.append(x_v)
                y.append(y_v)
            st = f.readline()

    x = np.array(x)
    y = np.array(y)

    def mnk(x, y):
        m = x.shape[0]
        x1 = np.sum(np.log(x))/m
        xx = np.sum(np.log(x)*np.log(x))/m
        xy = np.sum(np.log(y)*np.log(x))/m
        y1 = np.sum(np.log(y))/m

        D = xx - x1**2
        alpha = (xy - y1*x1)/D
        beta = (y1*xx - x1*xy)/(D)
        beta = np.exp(beta)
        return alpha, beta

    def mnk_no_b(x, y):
        return np.sum(np.log(y)*np.log(x))/np.sum(np.log(x)**2)

    X = np.linspace(min(x),max(x),10000)

    alpha, beta = mnk(x, y)
    ax.scatter(x, y, s=8, c=CLR2[i], edgecolors='k')
    ax.plot(X, beta * X**alpha, CLR[i], label=f'{i+1}, deg = {alpha}')


plt.title("График зависимости T(N)")
plt.grid(visible=True)
plt.xlabel("N")
plt.ylabel("T, ns")
plt.legend()
plt.show()
