cmake_minimum_required(VERSION 3.16)
project(lab1RegExp)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_REGEX_STANDALONE)

include_directories(src)
add_subdirectory(src)

add_executable(lab1RegExp main.cpp)

target_link_libraries(lab1RegExp src)