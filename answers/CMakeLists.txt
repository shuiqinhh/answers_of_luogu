cmake_minimum_required(VERSION 3.16.3)

project(luogu_answers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)




add_executable(B2158 B2158.cpp)
add_executable(P2550 P2550.cpp)
add_executable(P2669 P2669.cpp)
add_executable(P2750 P2750.cpp)
add_executable(P5613 P5613.cpp)
add_executable(P6206 P6206.cpp)
add_executable(P6565 P6565.cpp)


if(MSVC)
    add_compile_options(/utf-8)
endif()