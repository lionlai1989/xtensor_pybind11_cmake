cmake_minimum_required(VERSION 3.22)

project(mymodule)

# Must be submodule. Cannot be installed with pip
add_subdirectory(extern/pybind11)

# Use FetchContent
# include(FetchContent)
# # Download and configure xtl
# FetchContent_Declare(xtl
#     GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
#     GIT_TAG master
#     OVERRIDE_FIND_PACKAGE
# )
# FetchContent_MakeAvailable(xtl)
# # Download and configure xtensor
# FetchContent_Declare(xtensor
#     GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
#     GIT_TAG master
#     OVERRIDE_FIND_PACKAGE
# )
# FetchContent_MakeAvailable(xtensor)
# # Download and configure xsimd
# FetchContent_Declare(xsimd
#     GIT_REPOSITORY https://github.com/xtensor-stack/xsimd.git
#     GIT_TAG master
#     OVERRIDE_FIND_PACKAGE
# )
# FetchContent_MakeAvailable(xsimd)

# Use add_subdirectory
add_subdirectory(extern/xtl)
add_subdirectory(extern/xtensor)
add_subdirectory(extern/xsimd)

add_subdirectory(extern/xtensor-python)

find_package(Python REQUIRED COMPONENTS Interpreter Development NumPy)

pybind11_add_module(mymodule src/main.cpp)
target_link_libraries(mymodule PUBLIC xtensor pybind11::module xtensor-python Python::NumPy)
# Uncomment the line below to enable optimization
# target_link_libraries(mymodule PUBLIC xtensor pybind11::module xtensor-python Python::NumPy xtensor::optimize xtensor::use_xsimd)

target_compile_definitions(mymodule PRIVATE VERSION_INFO=0.1.0)
