project(catholiccorpusgenerator)
cmake_minimum_required(VERSION 2.8)


add_executable(catholiccorpusgenerator
  src/main.cpp
  src/fileparsers/livredesdemeures_parser.cpp
  src/fileparsers/livredesdemeures_parser.hpp
  src/fileparsers/virtualfileparser.cpp
  src/fileparsers/virtualfileparser.hpp
)

target_compile_features(catholiccorpusgenerator PRIVATE cxx_std_17)
