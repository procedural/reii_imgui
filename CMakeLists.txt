project(program C)
cmake_minimum_required(VERSION 2.8)

add_executable(program main.c reii.c)

target_link_libraries(program
  -lm
  -lGL
  "${CMAKE_SOURCE_DIR}/libglfw.so.3"
  "${CMAKE_SOURCE_DIR}/libimgui.so"
)

execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ../NotoSans.ttf NotoSans.ttf)