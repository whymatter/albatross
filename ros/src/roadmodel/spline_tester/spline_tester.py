import matplotlib.pyplot as plt
import numpy as np

x = np.array([
    1,
    4,
    7,
    10
])

a = np.array([
    1,
    3,
    8,
    3
])

b = np.array([
    0.253552,
    1.4929,
    0.774863,
    0
])

c = np.array([
    0,
    0.413115,
    -0.652459,
    0
])

d = np.array([
    0.0459016,
    -0.118397,
    0.0434973,
    0
])

#
# SOME NEW VALUES
#


x = np.array([
    1,
    4,
    7,
    2
])

a = np.array([
    1,
    3,
    8,
    15
])

b = np.array([
    0.253552,
    1.4929,
    0.774863,
    0
])

c = np.array([
    0,
    0.413115,
    -0.652459,
    0
])

d = np.array([
    0.0459016,
    -0.118397,
    0.0434973,
    0
])

n = x.shape[0]

for i in range(n - 1):
    # evenly sampled time at 200ms intervals
    t = np.arange(min(x[i], x[i + 1]), max(x[i], x[i + 1]), 0.01)
    # red dashes, blue squares and green triangles
    plt.plot(t, a[i] + b[i] * (t - x[i]) + c[i] * (t - x[i]) ** 2 + d[i] * (t - x[i]) ** 3)

plt.plot(x, a, 'ro')
plt.grid(True)
plt.show()
