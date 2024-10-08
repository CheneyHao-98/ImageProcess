/**
* @file GaussianFiltering.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-10-09
*
* @copyright Copyright (c) 2024
*
*/
#include "GaussianFiltering.hpp"

void GaussianFiltering::algorithm(cv::Mat& image){
    cv::Mat filteredImage = image.clone();
    int halfSize = m_kernelSize / 2;
    // 滤波操作
    for (int y = halfSize; y < image.rows - halfSize; ++y) {
        for (int x = halfSize; x < image.cols - halfSize; ++x) {
            double newValue = 0.0;
            for (int ky = -halfSize; ky <= halfSize; ++ky) {
                for (int kx = -halfSize; kx <= halfSize; ++kx) {
                    newValue += image.at<u_char>(y + ky, x + kx) * m_kernel.at<double>(ky + halfSize, kx + halfSize);
                }
            }
        filteredImage.at<u_char>(y, x) = cv::saturate_cast<uchar>(newValue);
        }
    }
    filteredImage.copyTo(image);
}

void GaussianFiltering::generateGaussianKernel(){
    int halfSize = m_kernelSize / 2;
    m_kernel = cv::Mat(m_kernelSize, m_kernelSize, CV_64F);
    double sum = 0.0;

    for (int y = -halfSize; y <= halfSize; y++) {
        for (int x = -halfSize; x <= halfSize; x++) {
            double value = exp(-(x * x + y * y) / (2 * m_sigma * m_sigma));
            m_kernel.at<double>(y + halfSize, x + halfSize) = value;
            sum += value;
        }
    }
    // 归一化核，使其权重和为 1
    m_kernel /= sum;
}
