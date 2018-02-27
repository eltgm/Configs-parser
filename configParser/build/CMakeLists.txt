cmake_minimum_required(VERSION 2.8.12)
project(ConfigParse)

set (SOURCES
 ../src/parser.cpp
)

set (HEADERS
 ../headers/func.h
 ../headers/config.h
)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Xml REQUIRED)

# Tell CMake to create the main executable
add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Xml)
