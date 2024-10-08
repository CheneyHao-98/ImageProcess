# 添加源文件
set(SOURCES ImageOperationBase.cpp)

# 使用 GLOB 查找某个目录下的所有 .cpp 文件
file(GLOB DIRECTORY_SOURCES
    "FormatConvert/*.cpp"
    "Enhancement/*.cpp"
    "Smoothing/*.cpp"
)

# 将目录下的源文件和头文件添加到 SOURCES 列表中
list(APPEND SOURCES ${DIRECTORY_SOURCES})

# 编译为共享库（动态库）
add_library(image_operations SHARED ${SOURCES})

# 将头文件添加到目标的接口
target_include_directories(image_operations PUBLIC
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/FormatConvert/
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/Enhancement/
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/Smoothing/
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/
)

# 链接 OpenCV 库
target_link_libraries(image_operations ${OpenCV_LIBS})

# 指定输出路径
set_target_properties(image_operations PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
