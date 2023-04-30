project(catholiccorpusgenerator)
cmake_minimum_required(VERSION 2.8)


add_executable(catholiccorpusgenerator
  src/main.cpp
  src/fileparsers/saintethereseavila_parser.cpp
  src/fileparsers/saintethereseavila_parser.hpp
  src/fileparsers/generic_parser.cpp
  src/fileparsers/generic_parser.hpp
  src/fileparsers/virtualfileparser.cpp
  src/fileparsers/virtualfileparser.hpp
  src/util/util.hpp
  src/util/util.cpp
)

target_compile_features(catholiccorpusgenerator PRIVATE cxx_std_17)
