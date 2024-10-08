/**
* @file NonLinearStretch.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-30
*
* @copyright Copyright (c) 2024
*
*/
#include <vector>
#include "NonLinearStretch.hpp"

void LogTransform::algorithm(cv::Mat& image){
    //设置常数c，通过调整c控制对比度的强度
    double maxVal,c;
    cv::minMaxLoc(image, nullptr, &maxVal);
    c = 255/std::log(1 + maxVal);
    //将图像转换为浮点格式，以便进行对数运算
    image.convertTo(image,CV_32F);
    //规避对数运算中的log0问题
    image += 1;
    cv::log(image,image);
    image *= c;
    //将结果转换回原始的图像类型,从32F转回8U相当于是缩方(不是归一化)
    image.convertTo(image,CV_8U);
}

void HistogramEqualization::algorithm(cv::Mat& image){
    //1.计算直方图
    int hist[256] = {0};
    for(int i = 0;i < image.rows; i++){
        for(int j = 0;j < image.cols; j++){
            hist[image.at<u_char>(i,j)]++;
        }
    }
    //2.计算累计分布函数(CDF)
    int cdf[256] = {0};
    cdf[0] = hist[0];
    for(int i = 1; i<256; i++){
        cdf[i] = cdf[i-1] + hist[i];
    }
    //3.计算CDF的归一化值
    //确保CDF从最小值0开始,找到第一个非0值，即最小值，然后计算新的灰度值
    int totalPixels = image.rows * image.cols;//图像总像素数
    float cdfMin = 0;
    for(int i = 0;i < 256;i++){
        if(cdf[i] > 0){
            cdfMin = cdf[i];
            break;
        }
    }
    //4.通过CDF映射灰度值
    cv::Mat result = image.clone();
    for(int i = 0;i < image.rows; i++){
        for(int j = 0;j < image.cols; j++){
            int oldPixel = image.at<u_char>(i,j);
            int newPixel = cv::saturate_cast<u_char>((cdf[oldPixel]-cdfMin)*255/(totalPixels-cdfMin));
            result.at<u_char>(i,j) = newPixel;
        }
    }
    result.copyTo(image);
}