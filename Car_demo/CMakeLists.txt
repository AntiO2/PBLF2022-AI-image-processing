cmake_minimum_required(VERSION 3.0.0)
project(car)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(OpenCV 3.2.0 REQUIRED)
include_directories(.)
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(thirdparty)
set(SOURCE_FILES
        src/core/core_func.cpp
        src/core/chars_identify.cpp
        src/core/chars_recognise.cpp
        src/core/chars_segment.cpp
        src/core/feature.cpp
        src/core/plate_detect.cpp
        src/core/plate_judge.cpp
        src/core/plate_locate.cpp
        src/core/plate_recognize.cpp
        src/core/params.cpp

        src/train/ann_train.cpp
        src/train/annCh_train.cpp
        src/train/svm_train.cpp
        src/train/train.cpp
        src/train/create_data.cpp

        src/util/util.cpp
        src/util/program_options.cpp
        src/util/kv.cpp
        )
add_library(easypr STATIC ${SOURCE_FILES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_NAME "app")
add_executable(${EXECUTABLE_NAME} app.cpp)
target_link_libraries(${EXECUTABLE_NAME} easypr thirdparty ${OpenCV_LIBS})
