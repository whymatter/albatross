//
// Created by seitz on 11/21/20.
//

#pragma once

#pragma once

#include <Eigen/Dense>
#include <chrono>
#include <ros/ros.h>

#include "matrix.h"

Eigen::MatrixXd splineHobby(const MatrixX2d &knots);