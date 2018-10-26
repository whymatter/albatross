from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
import numpy as np

import matplotlib.pyplot as plt

from image_shift import shift_images, plot_results

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

x = tf.placeholder(tf.float32, [None, 784])
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

y = tf.nn.softmax(tf.matmul(x, W))
y_ = tf.placeholder(tf.float32, [None, 10])
cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))

train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)

sess = tf.InteractiveSession()
tf.global_variables_initializer().run()

for _ in range(1000):
    batch_xs, batch_ys = mnist.train.next_batch(1000)
    sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))


def run_shifted_session(shift):
    shifted = shift_images(mnist.test.images, shift)
    run = sess.run(accuracy, feed_dict={x: shifted, y_: mnist.test.labels})
    return run


# original images
print('original:', sess.run(accuracy, feed_dict={x: mnist.test.images, y_: mnist.test.labels}))

# shifted images
SHIFT = (1, 1)
print('shifted: ', run_shifted_session(SHIFT))

# plot shift impact
_x = np.arange(7) - 3
_y = np.arange(7) - 3

_z1 = [run_shifted_session((xx, 0)) for xx in _x]
_z2 = [run_shifted_session((0, yy)) for yy in _y]
_z3 = [run_shifted_session((yy, yy)) for yy in _y]

plot_results(_z1, _z2, _z3)



# top = [run_shifted_session((xx, yy)) for xx in _x for yy in _y]
# bottom = np.zeros_like(top)
# width = depth = 1
#
# _xx, _yy = np.meshgrid(_x, _y)
# x, y = _xx.ravel(), _yy.ravel()
#
# fig = plt.figure(figsize=(8, 8))
# ax1 = fig.add_subplot(111, projection='3d')
# ax1.bar3d(x, y, bottom, width, depth, top)
# ax1.set_title('accuracy')
# plt.show()


# file = open('./export/weights.txt', 'w')
# np.set_printoptions(threshold=800 * 10)
# file.write(np.array_str(sess.run(W)))
# file.close()
# print(sess.run(y, feed_dict={x: np.array(
#     [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.2, 0.2, 0.2, 0, 0.6235294117647059, 0.6235294117647059, 0.6235294117647059, 0,
#       0.9921568627450981, 0.9921568627450981, 0.9921568627450981, 0, 0.6235294117647059, 0.6235294117647059,
#       0.6235294117647059, 0, 0.19607843137254902, 0.19607843137254902, 0.19607843137254902, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0.18823529411764706, 0.18823529411764706, 0.18823529411764706, 0, 0.9333333333333333,
#       0.9333333333333333, 0.9333333333333333, 0, 0.9882352941176471, 0.9882352941176471, 0.9882352941176471, 0,
#       0.9882352941176471, 0.9882352941176471, 0.9882352941176471, 0, 0.9882352941176471, 0.9882352941176471,
#       0.9882352941176471, 0, 0.9294117647058824, 0.9294117647058824, 0.9294117647058824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0.21176470588235294, 0.21176470588235294, 0.21176470588235294, 0, 0.8901960784313725, 0.8901960784313725,
#       0.8901960784313725, 0, 0.9921568627450981, 0.9921568627450981, 0.9921568627450981, 0, 0.9882352941176471,
#       0.9882352941176471, 0.9882352941176471, 0, 0.9372549019607843, 0.9372549019607843, 0.9372549019607843, 0,
#       0.9137254901960784, 0.9137254901960784, 0.9137254901960784, 0, 0.9882352941176471, 0.9882352941176471,
#       0.9882352941176471, 0, 0.2235294117647059, 0.2235294117647059, 0.2235294117647059, 0, 0.023529411764705882,
#       0.023529411764705882, 0.023529411764705882, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#       0, 0, 0, 0, 0, 0]],
#     dtype=np.float32)}))
