cmake_minimum_required(VERSION 3.22)
project(fonts_lib LANGUAGES C)
add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
	src/font8.c
	src/font12.c
	src/font16.c
	src/font20.c
	src/font24.c
)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_LOCAL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)