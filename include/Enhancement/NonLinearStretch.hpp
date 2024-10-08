#ifndef __NONLINEARSTRETCH__H__
#define __NONLINEARSTRETCH__H__
#include "ImageOperationBase.hpp"

class LogTransform : public ImageOperationBase{
public:
    LogTransform(){}
    void algorithm(cv::Mat& image) override;
};

class HistogramEqualization : public ImageOperationBase{
public:
    HistogramEqualization(){}
    void algorithm(cv::Mat& image) override;
};

#endif //!__NONLINEARSTRETCH__H__