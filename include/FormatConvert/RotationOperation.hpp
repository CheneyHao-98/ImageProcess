#ifndef __ROTATIONOPERATION__H__
#define __ROTATIONOPERATION__H__
#include "ImageOperationBase.hpp"

class RotationOperation : public ImageOperationBase{
public:
    RotationOperation(double angle)
                : m_rotateAngle(angle){}
    void algorithm(cv::Mat& image) override;
private:
    double m_rotateAngle;
};

#endif //!__ROTATIONOPERATION__H__