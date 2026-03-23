cmake_minimum_required(VERSION 3.22.0)
project(tft_display_lib VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(Fonts)
add_subdirectory(lcd)
add_subdirectory(printf)
add_subdirectory(touch)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)