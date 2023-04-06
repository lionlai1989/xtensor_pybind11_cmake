cmake_minimum_required(VERSION 3.22)

project(mymodule)

add_subdirectory(extern/pybind11)

add_subdirectory(extern/xtl)
add_subdirectory(extern/xtensor)
add_subdirectory(extern/xsimd)
add_subdirectory(extern/xtensor-python)

find_package(Python REQUIRED COMPONENTS Interpreter Development NumPy)

add_subdirectory(src/mypackage)

pybind11_add_module(mymodule src/main.cpp)
target_include_directories(mymodule PUBLIC xtensor xtl xtensor-python pybind11 src)
target_link_libraries(mymodule PUBLIC xtensor pybind11::module xtensor-python Python::NumPy sum_of_sines_static)

target_compile_definitions(mymodule PRIVATE VERSION_INFO=0.1.0)
