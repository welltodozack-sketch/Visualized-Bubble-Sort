cmake_minimum_required(VERSION 3.16)
project(VisualizedBubbleSort)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(VBS src/Source.cpp)

set(SFML_ROOT ${CMAKE_SOURCE_DIR}/libraries/SFML)

target_include_directories(VBS PRIVATE ${SFML_ROOT}/include)

target_link_directories(VBS PRIVATE ${SFML_ROOT}/lib)

target_link_libraries(VBS sfml-system)
target_link_libraries(VBS sfml-window)
target_link_libraries(VBS sfml-audio)
target_link_libraries(VBS sfml-graphics)