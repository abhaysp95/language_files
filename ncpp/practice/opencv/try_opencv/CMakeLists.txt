cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(opencv)

add_executable(${PROJECT_NAME} contours.cpp)

if(UNIX)
find_package(PkgConfig REQUIRED)
endif(UNIX)

find_package(OpenCV REQUIRED core imgcodecs imgproc HINTS ${CMAKE_CURRENT_LIST_DIR}/opencv/build)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
