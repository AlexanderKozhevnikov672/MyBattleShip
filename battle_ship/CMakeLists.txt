project(Play)

cmake_minimum_required(VERSION 3.0)

set(EXECUTABLE_OUTPUT_PATH ../bin)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
  "${PROJECT_SOURCE_DIR}/include/*.hpp"
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Play
  main.cpp
  ${all_SRCS}
)
