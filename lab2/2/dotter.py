import matplotlib.pyplot as plt
import numpy as np

x = []
y = []

'''First insert data.txt file
    to the dotter folder'''

filename = input("Enter filename: ")

with open(filename, 'r') as f:
    st = f.readline()
    while st:
        x_v, y_v = map(float, st.split())
        x.append(x_v)
        y.append(y_v)
        st = f.readline()

X = np.linspace(min(x),max(x),100)
fig, ax = plt.subplots()

ax.scatter(x, y, 5, 'b')

plt.title("График зависимости T(N)")
plt.xlabel("Размер массива N")
plt.ylabel("Время работы T, ns")
plt.grid(visible=True)
plt.show()
