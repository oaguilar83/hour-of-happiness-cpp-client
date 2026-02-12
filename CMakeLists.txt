cmake_minimum_required(VERSION 3.22)
project(HoHClient CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(external/cpr)
add_subdirectory(external/json)
