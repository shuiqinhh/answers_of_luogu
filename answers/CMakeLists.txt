cmake_minimum_required(VERSION 3.16.3)

project(luogu_answers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

find_package(OpenCV REQUIRED)
message("opencv included successfully")

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(my_first_code testing.cpp)
add_executable(video_capture_edge video_capture_test.cpp)

target_link_libraries(my_first_code ${OpenCV_LIBS})
target_link_libraries(video_capture_edge ${OpenCV_LIBS})