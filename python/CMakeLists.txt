cmake_minimum_required(VERSION 3.15...3.30)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
# Need to use libc++ stl implementation not libstdc++ (seems like SG compiled
# using this implementation which changes the names of symbols in the shared
# library)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
include_directories("../include" "pybind11/include")
link_directories("../lib/linux/v22/x86-64/release" "/usr/lib/x86_64-linux-gnu/")
project(py_sgdk1 LANGUAGES CXX)

add_subdirectory(pybind11)
pybind11_add_module(py_sgdk1 python.cpp)
install(TARGETS py_sgdk1 DESTINATION .)

target_link_libraries(py_sgdk1 PUBLIC sgcore sgconnect sgcore sgconnect)