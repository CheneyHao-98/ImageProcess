#ifndef __GAUSSIANFILTERING__H__
#define __GAUSSIANFILTERING__H__
#include "ImageOperationBase.hpp"

class GaussianFiltering : public ImageOperationBase{
public:
    GaussianFiltering(int kernalSize,double sigma)
        : m_kernelSize(kernalSize), m_sigma(sigma)
    {
        generateGaussianKernel();
    }
    void algorithm(cv::Mat& image) override;

private:
    void generateGaussianKernel();

private:
    int m_kernelSize;
    double m_sigma;
    cv::Mat m_kernel; // 存储高斯核
};

#endif //!__GAUSSIANFILTERING__H__
