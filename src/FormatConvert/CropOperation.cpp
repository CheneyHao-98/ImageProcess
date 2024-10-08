/**
* @file CropOperation.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-27
*
* @copyright Copyright (c) 2024
*
*/
#include "CropOperation.hpp"

void CropOperation::algorithm(cv::Mat& image){
    //确保裁剪区域在图像范围内
    int x_end = std::min(m_x + m_width,image.cols);
    int y_end = std::min(m_y + m_height,image.rows);
    //检查裁剪区域是否合法
    if((m_x < 0)||(m_y < 0)||(x_end < m_x)||(y_end < m_y)){
        std::cerr << "Invalid crop erae. "<<std::endl;
    }
    //执行裁剪
    cv::Rect cropRegion(m_x,m_y,x_end-m_x,y_end-m_y);
    image = image(cropRegion);
}