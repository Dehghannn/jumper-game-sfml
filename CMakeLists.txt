cmake_minimum_required(VERSION 3.0)
project (jumper)

#tells cmake where to find the configuration file for SFML
#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

add_definitions("-std=c++17")

#searches for the installed SFML libraries via the FindSFML file specified by CMAKE_MODULE_PATH
#find_package(SFML 2 REQUIRED graphics window audio system network)

#tells the project to use the installed SFML include directory
#include_directories(${SFML_INCLUDE_DIR})

set(SRC src/main.cpp src/game.cpp src/jumper.cpp src/entity.cpp src/gamestate.cpp src/playstate.cpp src/startstate.cpp)

add_executable(jumper ${SRC})

#links the libraries specified by find_package (and ensures correct link order)
if(UNIX)
    target_link_libraries( jumper sfml-system)
    target_link_libraries( jumper sfml-window)
    target_link_libraries( jumper sfml-graphics)
    target_link_libraries( jumper sfml-audio)
    target_link_libraries( jumper sfml-network)
endif()
set(CMAKE_PREFIX_PATH ./build/)

if(WIN32)
    target_include_directories( jumper PUBLIC C:/SFML-2.5.1/include)
    target_link_directories( jumper PUBLIC C:/SFML-2.5.1/bin)
    target_link_libraries( jumper sfml-system-2)
    target_link_libraries( jumper sfml-window-2)
    target_link_libraries( jumper sfml-graphics-2)
    target_link_libraries( jumper sfml-audio-2)
    target_link_libraries( jumper sfml-network-2)
    
endif()