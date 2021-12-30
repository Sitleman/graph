cmake_minimum_required(VERSION 3.16)
project(algo)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(IGraph)
add_subdirectory(ListGraph)
add_subdirectory(MatrixGraph)
add_subdirectory(ArcGraph)
add_subdirectory(SetGraph)

add_executable(algo main.cpp)
target_link_libraries(algo PUBLIC ListGraph MatrixGraph SetGraph ArcGraph)