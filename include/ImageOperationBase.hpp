#ifndef __IMAGEOPERATIONBASE__H__
#define __IMAGEOPERATIONBASE__H__
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

class ImageOperationBase{
public:
    virtual ~ImageOperationBase(){};
    void apply(cv::Mat& image);
    virtual void algorithm(cv::Mat& image) = 0;
};

class ImageProcessor{
public:
    ImageProcessor() = default;
    ~ImageProcessor() = default;
    void addOperation(std::unique_ptr<ImageOperationBase> operationPtr);
    void process(const std::string& filename, int imageColor = 1);
    static int processNum;
private:
    void printBasicInfo(cv::Mat& image);
    void display(cv::Mat& image);
    std::vector<std::unique_ptr<ImageOperationBase>> m_operatinos;
};

#endif //!__IMAGEOPERATION__H__