cmake_minimum_required(VERSION 3.23)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
link_libraries(libeasyx.a)
link_libraries(libEasyX.a libgdi32.a libole32.a)
add_executable(Chess main.cpp Myboard.cpp Myboard.h chess.cpp chess.h)



