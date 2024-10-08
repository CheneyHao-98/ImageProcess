cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(ImageOperations VERSION 1.0)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 添加子目录
add_subdirectory(src)

# 添加选项控制是否编译demo
option(BUILD_TEST "Build the test executable" ON)
if(BUILD_TEST)
    add_subdirectory(test)
endif()