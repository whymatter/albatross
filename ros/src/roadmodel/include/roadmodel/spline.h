//
// Created by whymatter on 14.08.19.
//

#pragma once

#include <Eigen/Dense>
#include <chrono>
#include <ros/ros.h>

#include "matrix.h"

Eigen::MatrixXd spline(const MatrixX2d &knots);