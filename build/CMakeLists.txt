cmake_minimum_required(VERSION 2.8)

project(test)
set(CMAKE_PREFIX_PATH=/home/eltgm/Qt/5.3/gcc_64/lib/cmake)
set (LIBRARIES
                ConfigParse)
 add_subdirectory (../configParser/build bin/${LIBRARY})

set (HEADERS)
set (SOURCES ../main.cpp)

add_executable (${PROJECT_NAME} WIN32 ${HEADERS} ${SOURCES})
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
