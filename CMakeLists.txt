cmake_minimum_required(VERSION 3.16.3)

project(luogu_answers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)



# Luogu problems
add_executable(B2158 answers/B2158.cpp)
add_executable(P2550 answers/P2550.cpp)
add_executable(P2669 answers/P2669.cpp)
add_executable(P2750 answers/P2750.cpp)
add_executable(P5613 answers/P5613.cpp)
add_executable(P6206 answers/P6206.cpp)
add_executable(P6565 answers/P6565.cpp)
add_executable(P1125 answers/P1125.cpp)
add_executable(P1059 answers/P1059.cpp)
add_executable(P1936 answers/P1936.cpp)
add_executable(P1116 answers/P1116.cpp)
add_executable(P1996 answers/P1996.cpp)
add_executable(B2105 answers/B2105.cpp)
add_executable(B4358 answers/B4358.cpp)
add_executable(B2165 answers/B2165.cpp)
add_executable(P1760 answers/P1760.cpp)

# algorithms
add_executable(permution_Recursion algorithms/permution_Recursion.cpp)
add_executable(sorting_algorithms algorithms/sorting_algorithms.cpp)
add_executable(Josephus_question algorithms/Josephus_question.cpp)
add_executable(numstack algorithms/numstack.cpp)
add_executable(recursive_solution_hanoi algorithms/Towerofhanoi/recursive_solution.cpp)
add_executable(stack_solution_hanoi algorithms/Towerofhanoi/stack_solution.cpp)

if(MSVC)
    add_compile_options(/utf-8)
endif()