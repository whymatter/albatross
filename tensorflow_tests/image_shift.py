import numpy as np
import matplotlib.pyplot as plt


def shift_images(images, shift):
    # reshape into matrix
    images_reshaped = images.reshape(10000, 28, 28)

    x_shift = shift[0]
    y_shift = shift[1]

    x_slice_min = None if x_shift >= 0 else -x_shift
    y_slice_min = None if y_shift >= 0 else -y_shift

    x_slice_max = None if x_shift <= 0 else -x_shift
    y_slice_max = None if y_shift <= 0 else -y_shift

    # right and bottom pad images with zeros
    images_padded = np.zeros((10000, 28 + abs(y_shift), 28 + abs(x_shift)))
    images_padded[:, y_slice_min:y_slice_max, x_slice_min:x_slice_max] = images_reshaped

    # roll (shift) images to the right
    images_shifted = np.roll(images_padded, x_shift, axis=2)
    # roll (shift) images to the bottom
    images_shifted = np.roll(images_shifted, y_shift, axis=1)

    # reshape backwards
    return images_shifted[:, y_slice_min:y_slice_max, x_slice_min:x_slice_max].reshape(10000, 28 * 28)


def plot_results(_x, _y, z1, z2, z3):
    fig = plt.figure(figsize=(8, 8))
    ax1 = fig.add_subplot(221, ylabel='accuracy', xlabel='x-shift')
    ax2 = fig.add_subplot(222, ylabel='accuracy', xlabel='y-shift')
    ax3 = fig.add_subplot(212, ylabel='accuracy', xlabel='x/y-shift')

    if z1 is not None:
        (marker_line, stem_lines, baseline) = ax1.stem(_x, z1, '-')
        plt.setp(marker_line, markersize=5, marker='o', mfc='black', mec='black')
        plt.setp(baseline, color='black', linewidth=1)
        plt.setp(stem_lines, color='blue', linewidth=1)

    if z2 is not None:
        (marker_line, stem_lines, baseline) = ax2.stem(_y, z2, '-')
        plt.setp(marker_line, markersize=5, marker='o', mfc='black', mec='black')
        plt.setp(baseline, color='black', linewidth=1)
        plt.setp(stem_lines, color='blue', linewidth=1)

    if z3 is not None:
        (marker_line, stem_lines, baseline) = ax3.stem(_y, z3, '-')
        plt.setp(marker_line, markersize=5, marker='o', mfc='black', mec='black')
        plt.setp(baseline, color='black', linewidth=1)
        plt.setp(stem_lines, color='blue', linewidth=1)

    plt.show()
