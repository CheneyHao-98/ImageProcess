#ifndef __LINEARSTRETCH__H__
#define __LINEARSTRETCH__H__
#include "ImageOperationBase.hpp"

class LinearStretch : public ImageOperationBase{
public:
    LinearStretch(double minBright, double maxBright)
            : m_minBright(minBright),m_maxBright(maxBright){}
    void algorithm(cv::Mat& image) override;
private:
    double m_minBright;
    double m_maxBright;
};

#endif //!__LINEARSTRETCH__H__