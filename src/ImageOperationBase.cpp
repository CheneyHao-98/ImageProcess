/**
* @file ImageOperationBase.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-27
*
* @copyright Copyright (c) 2024
*
*/
#include <chrono>
#include "ImageOperationBase.hpp"

void ImageOperationBase::apply(cv::Mat& image){
    if (image.channels() == 1) {
        algorithm(image);
    } else if (image.channels() == 3) {
        // 分离通道
        std::vector<cv::Mat> channels(3);
        cv::split(image, channels);
        // 对每个通道执行算法
        for (int i = 0; i < 3; i++) {
            algorithm(channels[i]);
        }
        // 合并通道
        cv::merge(channels, image);
    } else {
        std::cout << "Unsuppoted image channels." << std::endl;
    }
}


int ImageProcessor::processNum = 0;

void ImageProcessor::addOperation(std::unique_ptr<ImageOperationBase> operationPtr){
    if(operationPtr == nullptr){
        return;
    }
    m_operatinos.push_back(std::move(operationPtr));
}

void ImageProcessor::process(const std::string& filename, int imageColor){
    cv::Mat input = cv::imread(filename,imageColor);
    std::cout<<"************************Basic info*************************"<<std::endl;
    printBasicInfo(input);
    std::cout<<"***********************************************************"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for(const auto& operation:m_operatinos){
        if(operation == nullptr){
            break;
        }
        operation->apply(input);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> duration = end - start;
    std::cout<<"************************After process***********************"<<std::endl;
    printBasicInfo(input);
    std::cout<<"***********************************************************"<<std::endl;
    std::cout<<"processing cost time "<<duration.count()<<std::endl;
    std::cout<<"***********************************************************"<<std::endl;
    display(input);
}

void ImageProcessor::printBasicInfo(cv::Mat& image){
    if(image.empty()){
        std::cerr << "Can not open the image." <<std::endl;
        return;
    }
    std::cout<< "Input resolution : "<< image.cols << "x" << image.rows <<std::endl;
    std::cout<< "Number of input channels : "<< image.channels() << std::endl;
    double minBright, maxBright, meanBright;
    if(image.channels() == 1){
        cv::minMaxLoc(image,&minBright,&maxBright);
        meanBright = cv::mean(image)[0];
        std::cout<< "Max bright value : "<< maxBright <<std::endl;
        std::cout<< "Min bright value : "<< minBright <<std::endl;
        std::cout<< "Bright value : "<< meanBright <<std::endl;
    }
    if(image.channels() == 3){
        std::vector<cv::Mat> channels;
        cv::split(image,channels);
        for(int i = 0;i < 3;i++){
            cv::minMaxLoc(image,&minBright,&maxBright);
            meanBright = cv::mean(image)[i];
            std::string channelColor;
            if(i == 0) channelColor = "B";
            if(i == 1) channelColor = "G";
            if(i == 2) channelColor = "R";
            std::cout<< "Max bright value of channel "<< channelColor << " :" << maxBright <<std::endl;
            std::cout<< "Min bright value of channel "<< channelColor << " :" << minBright <<std::endl;
            std::cout<< "Bright value of channel "<< channelColor << " :" << meanBright <<std::endl;
        }
    }
}

void ImageProcessor::display(cv::Mat& image){
    processNum += 1;
    cv::imshow("Process " + std::to_string(processNum),image);
    cv::waitKey(0);
}