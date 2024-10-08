/**
* @file MeanFiltering.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-10-08
*
* @copyright Copyright (c) 2024
*
*/
#include "MeanFiltering.hpp"

void MeanFiltering::algorithm(cv::Mat& image){
    cv::Mat filterImage;
    cv::blur(image,filterImage,cv::Size(m_kernalSize,m_kernalSize));
    image = filterImage;
}

void MeanFilterWithIntegral::algorithm(cv::Mat& image) {
    // 计算积分图
    cv::Mat integralImage;
    cv::integral(image, integralImage, CV_32F);
    // 使用积分图快速计算均值
    cv::Mat filteredImage = cv::Mat::zeros(image.size(), image.type());
    int halfKernel = m_kernelSize / 2;
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            // 计算当前像素周围窗口区域的积分值
            int x1 = std::max(x - halfKernel, 0);
            int y1 = std::max(y - halfKernel, 0);
            int x2 = std::min(x + halfKernel, image.cols - 1);
            int y2 = std::min(y + halfKernel, image.rows - 1);

            int sum = integralImage.at<float>(y2 + 1, x2 + 1)
            - integralImage.at<float>(y1, x2 + 1)
            - integralImage.at<float>(y2 + 1, x1)
            + integralImage.at<float>(y1, x1);
            // 计算窗口的平均值
            filteredImage.at<float>(y, x) = sum / (m_kernelSize * m_kernelSize);
        }
    }
    // 更新原始图像
    filteredImage.convertTo(image, CV_8U);
}