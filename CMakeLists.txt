cmake_minimum_required(VERSION 3.18)
project(graphicEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(graphicEditor main.cpp 
               consts.h 
               Canvas/canvas.cpp Canvas/canvas.h 
               Tools/tools.cpp Tools/tools.h
               Events/events.cpp Events/events.h
               Tools/baseTool.h
               Tools/ToolBar/toolBar.cpp Tools/ToolBar/toolBar.h
               Tools/ToolManager/toolManager.cpp Tools/ToolManager/toolManager.h
               Hsv/hsv.cpp Hsv/hsv.h
               Hsv/HsvConverter/hsvConverter.cpp Hsv/HsvConverter/hsvConverter.h
               ColorPicker/colorPicker.cpp ColorPicker/colorPicker.h
               VisualOptions/thickSlider/thickSlider.cpp VisualOptions/thickSlider/thickSlider.h
               TopMenu/topMenu.cpp TopMenu/topMenu.h)
               
target_link_libraries(graphicEditor sfml-graphics sfml-audio "/home/boris/CLionProjects/windowManager/cmake-build-debug/libwindowManager.a")