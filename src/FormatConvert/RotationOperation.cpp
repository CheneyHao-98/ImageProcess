/**
* @file RotationOperation.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-27
*
* @copyright Copyright (c) 2024
*
*/
#include "RotationOperation.hpp"

void RotationOperation::algorithm(cv::Mat& image){
    //计算图像中心
    cv::Point2f center(image.cols/2.0,image.rows/2.0);
    //计算旋转矩阵
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, m_rotateAngle, 1.0);
    //应用旋转
    cv::warpAffine(image,image,rotationMatrix,image.size());
}