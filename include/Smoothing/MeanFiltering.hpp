#ifndef __MEANFILTERING__H__
#define __MEANFILTERING__H__
#include "ImageOperationBase.hpp"

class MeanFiltering : public ImageOperationBase{
public:
    MeanFiltering(int kernalSize)
        : m_kernalSize(kernalSize){}
    void algorithm(cv::Mat& image) override;
private:
    int m_kernalSize;
};

class MeanFilterWithIntegral : public ImageOperationBase {
public:
    MeanFilterWithIntegral(int kernelSize)
        : m_kernelSize(kernelSize) {}
    void algorithm(cv::Mat& image) override;
private:
    int m_kernelSize;
};

#endif //!__MEANFILTERING__H__
