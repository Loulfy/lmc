cmake_minimum_required(VERSION 3.9)
project(LMC)

set(CMAKE_CXX_STANDARD 14)

find_package(JNI)

include_directories(${JNI_INCLUDE_DIRS})

add_executable(LMC main.cpp)
target_link_libraries(LMC ${JNI_LIBRARIES})