cmake_minimum_required(VERSION 3.22)
project(printf_lib LANGUAGES C)
add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/printf.c)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)