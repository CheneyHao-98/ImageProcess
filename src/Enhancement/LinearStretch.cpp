/**
* @file LinearStretch.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-30
*
* @copyright Copyright (c) 2024
*
*/
#include <vector>
#include "LinearStretch.hpp"

void LinearStretch::algorithm(cv::Mat& image){
    // 获取当前通道的最小值和最大值
    double minVal, maxVal;
    cv::minMaxLoc(image, &minVal, &maxVal);
    if(minVal == maxVal) return;
    // 进行线性拉伸
    double k = (m_maxBright - m_minBright) / (maxVal - minVal);
    double b = m_minBright - (minVal * k);
    image.convertTo(image, CV_8U, k, b);
}