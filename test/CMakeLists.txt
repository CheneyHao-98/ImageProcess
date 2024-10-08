# 添加可执行文件
add_executable(image_processor_test main.cpp)

#链接共享库和Opencv库
target_link_libraries(image_processor_test
                      image_operations
                      ${OpenCV_LIBS})

#设置可执行文件的输出路径
set_target_properties(image_processor_test PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)