import numpy as np

def get_intrinsic_matrix(resolution):
    w_scale = resolution[0] / 1920.0
    h_scale = resolution[1] / 1080.0

    CAMERA_INTRINSIC_MATRIX = [
        [1414.25894999856 * w_scale, 0, 937.625189031865 * w_scale],
        [0, 1411.75549482935 * h_scale, 552.617728282796 * h_scale],
        [0, 0, 1]
    ]

    return np.array(CAMERA_INTRINSIC_MATRIX)


def get_distortion_coefficients():
    return np.array([
        0.029146493259967,       # k1
        -0.221044408671802,      # k2
        0.003460337109318,       # p1
        -3.196073231590876e-04,  # p2
        0.236567290041656        # k3
    ])
