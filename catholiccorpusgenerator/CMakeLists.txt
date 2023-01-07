project(catholiccorpusgenerator)
cmake_minimum_required(VERSION 2.8)


add_executable(catholiccorpusgenerator
  src/main.cpp
)

target_compile_features(catholiccorpusgenerator PRIVATE cxx_std_17)
