/**
* @file main.cpp
* @author your name (you@domain.com)
* @brief
* @version 0.1
* @date 2024-09-27
*
* @copyright Copyright (c) 2024
*
*/
#include <memory>
#include "ImageOperationBase.hpp"
#include "CropOperation.hpp"
#include "RotationOperation.hpp"
#include "LinearStretch.hpp"

int main(int argc, char* argv[])
{
    ImageProcessor processor;
    std::string commandSet = "";
    while(1){
        std::cout<<"*"<<std::endl;
        std::cout<<" Add the operation(pleasr enter the number): "<<std::endl;
        std::cout<<" 1. rotate "<<std::endl;
        std::cout<<" 2. crop "<<std::endl;
        std::cout<<" 3. LinearStretch "<<std::endl;
        std::cout<<" 0. done "<<std::endl;
        std::cout<<"Added command : "<<commandSet <<std::endl;
        std::cout<<"*"<<std::endl;
        std::string command;
        std::cin >> command;
        if(command == "1"){
            commandSet += "1 ";
            double angle;
            std::cout << "Enter rotation angle: " << std::endl;
            std::cin >> angle;
            processor.addOperation(std::make_unique<RotationOperation>(angle));
        }else if(command == "2"){
            commandSet += "2 ";
            int x,y,width,height;
            std::cout << "Enter crop parameters x: " << std::endl;
            std::cin >> x ;
            std::cout << "Enter crop parameters y: " << std::endl;
            std::cin >> y ;
            std::cout << "Enter crop parameters width: " << std::endl;
            std::cin >> width;
            std::cout << "Enter crop parameters height: " << std::endl;
            std::cin >> height;
            processor.addOperation(std::make_unique<CropOperation>(x,y,width,height));
        }else if(command == "3"){
            commandSet += "3 ";
            double minBright,maxBright;
            std::cout << "Enter linear stretch min bright: " << std::endl;
            std::cin >> minBright;
            std::cout << "Enter linear stretch max brightt: " << std::endl;
            std::cin >> maxBright;
            processor.addOperation(std::make_unique<LinearStretch>(minBright,maxBright));
        }else if(command == "0"){
            break;
        }else{
        std::cout << "Invalid input! " << std::endl;
        }
    }
    if(argc > 2){
        std::string imageColor = argv[2];
        if(imageColor == "grey"){
            processor.process(argv[1],0);
            return 0;
        }
    }
    processor.process(argv[1]);
}