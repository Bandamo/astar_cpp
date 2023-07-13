project(astar)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/usr/include)
include_directories(src)
include_directories(header)

set(SOURCES src/main.cpp src/astar.cpp src/pstar.cpp)
set(HEADERS header/main.hpp header/astar.hpp header/pstar.hpp)

add_executable(astar ${SOURCES} ${HEADERS}) 
