import matplotlib.pyplot as plt
import numpy as np

def xi_m(arr1, wgt, arr2=[]):
    if not arr2:
        arr2 = [1]*len(arr1)
    wg = [0]*len(arr1)
    s = 0
    for i in range(len(arr1)):
        wg[i] = 1/(wgt[i]*wgt[i])
    W = sum(wg)
    
    for i in range(len(arr1)):
        s += wg[i]*arr1[i]*arr2[i]
    return s/W

def D(arr1, arr2, wgt):
    return xi_m(arr1, wgt, arr2)-xi_m(arr1, wgt)*xi_m(arr2, wgt) 

def xi(x, y, wgt):
    k = D(x, y, wgt)/D(x, x, wgt)
    b = xi_m(y, wgt)-k*xi_m(x, wgt)
    s_k = np.sqrt((D(y, y, wgt)/D(x, x, wgt)-k*k)/(len(x)-2))
    s_b = s_k*np.sqrt(xi_m(x, wgt, x))
    return k, b, s_k, s_b

x = []
y = []
xerr = []
yerr = []

filename = input("Enter filename: ")

with open(filename, 'r') as f:
    st = f.readline()
    while st:
        x_v, y_v = map(float, st.split())
        x.append(x_v)
        y.append(y_v)
        st = f.readline()

n = len(x)
xerr = [0]*n
yerr = [0.00001]*n

fig, ax = plt.subplots()

X = np.linspace(min(x),max(x),100)

k, b, s_k, s_b = xi(x, y, yerr)
#print("k = ", k, "sigma_k = ", s_k)
#print("b = ", b, "sigma_b = ", s_b)

ax.errorbar(x, y, yerr, xerr, fmt='.b', linewidth=1, capsize=1, zorder=1)
ax.plot(X, k*X + b, 'r-')
ax.set_zorder(1)
ax.patch.set_visible(False)

plt.xlabel("N")
plt.ylabel("T, nsec")
plt.title("T(N)")
plt.grid(visible=True)
plt.show()
