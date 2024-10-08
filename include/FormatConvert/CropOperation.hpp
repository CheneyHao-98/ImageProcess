#ifndef __CROPOPERATION__H__
#define __CROPOPERATION__H__
#include "ImageOperationBase.hpp"

class CropOperation : public ImageOperationBase{
public:
    CropOperation(int x, int y, int width, int height)
            : m_x(x),m_y(y),m_width(width),m_height(height){}
    void algorithm(cv::Mat& image) override;
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

#endif //!__CROPOPERATION__H__