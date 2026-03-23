cmake_minimum_required(VERSION 3.22)
project(touch_lib LANGUAGES C CXX)
add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/FT6236.cpp)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/minimal-cmake>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)