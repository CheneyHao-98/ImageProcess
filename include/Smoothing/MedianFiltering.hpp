#ifndef __MEDIANFILTERING__H__
#define __MEDIANFILTERING__H__
#include "ImageOperationBase.hpp"

class MedianFiltering : public ImageOperationBase{
public:
    MedianFiltering(int kernalSize)
        : m_kernalSize(kernalSize){}
    void algorithm(cv::Mat& image) override;
private:
    int m_kernalSize;
};

#endif //!__MEDIANFILTERING__H__