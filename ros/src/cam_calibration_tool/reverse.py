import cv2
import numpy as np

import intrinsic_matrix

# points
M = np.array([126., 84., 0.])
m = np.array([403.90444946, 212.17770386])
Mz = M[2]

# intrinsic
A = intrinsic_matrix.get_intrinsic_matrix((640, 360))
A_ = np.linalg.inv(A)
print('intrinsic')
print(repr(A))
print('inverse intrinsic')
print(repr(A_))

D = intrinsic_matrix.get_distortion_coefficients()

# rotation
r = np.array([[2.02475405],
              [-0.0131705],
              [-0.01929892]])
R, _ = cv2.Rodrigues(r)
R_ = R.T
print('rotation')
print(repr(R))
print('inverse rotation')
print(repr(R_))

# transform
t = np.array([-13.12570513,
              73.43816089,
              506.93543688])

# world to image
t1 = np.dot(R, M) + t
print('R*M+t')
print(t1)
t1 = t1 / t1[2]
print('/z')
print(t1)
t2 = np.dot(A, t1)
print('A*(R*M+t) (image point)')
print(t2)
# t3 = t2 / t2[2]
# print('/z (ready image coordinates)')
# print(t3)

# image to world
m_ = np.append(m, 1.0)
t1 = np.dot(A_, m_)
print('A_*m_')
print(repr(t1))

# same effect but with undistortion
print('undistortPoints')
t1 = cv2.undistortPoints(np.array([[m]]), A, D)
t1 = np.append(t1, 1.0)
print(repr(t1))

R_A_m_ = np.dot(R_, t1)
R_t = np.dot(R_, t)
s = (M[2] + R_t[2]) / R_A_m_[2]
print('(Mz+R_t)/R_A_m_')
print(repr(s))

t1 = s*R_A_m_-R_t
print('s*R_A_m_-R_t (object point)')
print(t1)