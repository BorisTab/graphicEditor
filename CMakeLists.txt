cmake_minimum_required(VERSION 3.18)
project(graphicEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(graphicEditor main.cpp consts.h Canvas/canvas.cpp Canvas/canvas.h)
target_link_libraries(graphicEditor sfml-graphics sfml-audio "/home/boris/CLionProjects/windowManager/cmake-build-debug/libwindowManager.a")