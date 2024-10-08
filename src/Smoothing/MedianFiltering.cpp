/**
* @file MedianFiltering.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-10-09
*
* @copyright Copyright (c) 2024
*
*/
#include "MedianFiltering.hpp"

void MedianFiltering::algorithm(cv::Mat& image){
    cv::medianBlur(image,image,m_kernalSize);
}