cmake_minimum_required(VERSION 3.3)
project(ucd_csi2312_pa2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .gitignore
    README.md Point.h main.cpp  Cluster.h KMeans.cpp KMeans.h Exceptions.cpp Exceptions.h)

add_executable(ucd_csi2312_pa2 ${SOURCE_FILES})