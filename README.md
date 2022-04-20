# PBLF2022-AI-image-processing
PBLF2022人工智能图像处理  
这是一门选修课的源码和报告
## 系统环境
- Ubuntu 20.04.4 LTS
- gcc 9.4.0
- Python 3.8.10
- cmake version 3.16.3
- OpenCV 3.4.8

## 编译说明
直接使用`.\work.sh`


## 一些基本的CMake教学
- cmake_minimum_required(VERSION 2.8)指定了cmake的最低版本号为2.8。
- project(ImageTest)指定了工程名为ImageTest。
- find_package(OpenCV REQUIRED)快速引入文件依赖模块。
- set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}) 指定生成程序的路径。
- add_executable添加了一个可执行文件构筑目标。
- target_link_libraries将目标文件和第三方库链接。