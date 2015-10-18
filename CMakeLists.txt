cmake_minimum_required(VERSION 3.3)
project(ucd_csi2312_pa2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .gitignore
    README.md Point.cpp Point.h main.cpp Cluster.cpp Cluster.h KMeans.cpp KMeans.h)

add_executable(ucd_csi2312_pa2 ${SOURCE_FILES})