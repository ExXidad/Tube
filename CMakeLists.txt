cmake_minimum_required(VERSION 3.15)
project(Tube)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/xidad/libs/eigen-3.3.7)

add_executable(Tube main.cpp Tube.cpp Tube.h Graphics.cpp Graphics.h Node.cpp Node.h Line.cpp Line.h)

target_link_libraries(Tube -lsfml-graphics -lsfml-window -lsfml-system)