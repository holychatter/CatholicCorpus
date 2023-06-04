project(readwebpage)
cmake_minimum_required(VERSION 2.8)

# https://curl.se/download.html => install curl libraries and boostrap the curl
# Warning : download libraries curl and not executable

find_package(CURL REQUIRED)
message(STATUS "CURL_INCLUDE_DIR=${CURL_INCLUDE_DIR}")
message(STATUS "CURL_LIBRARIES=${CURL_LIBRARIES}")


add_executable(readwebpage
  src/main.cpp
  src/requester/externalrequester.hpp
  src/requester/internetrequester.hpp
  src/requester/internetrequester.cpp
)

target_compile_features(readwebpage PRIVATE cxx_std_17)

include_directories(
  ${CURL_INCLUDE_DIR}
)
target_link_libraries(readwebpage
  ${CURL_LIBRARIES}
)
