cmake_minimum_required(VERSION 2.6)
project (pacwoman)

#tells cmake where to find the configuration file for SFML
#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

add_definitions("-std=c++11")

#searches for the installed SFML libraries via the FindSFML file specified by CMAKE_MODULE_PATH
#find_package(SFML 2 REQUIRED graphics window audio system network)

#tells the project to use the installed SFML include directory
#include_directories(${SFML_INCLUDE_DIR})

set(SRC src/main.cpp)

add_executable(pacwoman ${SRC})

#links the libraries specified by find_package (and ensures correct link order)
target_link_libraries( pacwoman sfml-system)
target_link_libraries( pacwoman sfml-window)
target_link_libraries( pacwoman sfml-graphics)
target_link_libraries( pacwoman sfml-audio)
target_link_libraries( pacwoman sfml-network)

