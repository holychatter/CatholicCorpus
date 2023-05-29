project(catholiccorpusgenerator)
cmake_minimum_required(VERSION 2.8)

# https://curl.se/download.html => install curl libraries and boostrap the curl
# Warning : download libraries curl and not executable

find_package(CURL REQUIRED)
message(STATUS "CURL_INCLUDE_DIR=${CURL_INCLUDE_DIR}")
message(STATUS "CURL_LIBRARIES=${CURL_LIBRARIES}")


add_executable(catholiccorpusgenerator
  src/main.cpp
  src/fileparsers/saintethereseavila_parser.cpp
  src/fileparsers/saintethereseavila_parser.hpp
  src/fileparsers/generic_parser.cpp
  src/fileparsers/generic_parser.hpp
  src/fileparsers/virtualfileparser.cpp
  src/fileparsers/virtualfileparser.hpp
  src/requester/externalrequester.hpp
  src/requester/internetrequester.hpp
  src/requester/internetrequester.cpp
  src/util/util.hpp
  src/util/util.cpp
)

target_compile_features(catholiccorpusgenerator PRIVATE cxx_std_17)

include_directories(
  ${CURL_INCLUDE_DIR}
)
target_link_libraries(catholiccorpusgenerator
  ${CURL_LIBRARIES}
)
