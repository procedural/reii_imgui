project(program C)
cmake_minimum_required(VERSION 2.8)

add_executable(program main.c reii.c)

target_link_libraries(program
  -lm
  -lGL
  "${CMAKE_SOURCE_DIR}/libglfw.so.3"
)
