add_library(sum_of_sines_static STATIC)
target_sources(sum_of_sines_static PUBLIC sum_of_sines.cpp)

target_include_directories(sum_of_sines_static PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/extern)
target_link_libraries(sum_of_sines_static PUBLIC xtensor)
# target_link_libraries(sum_of_sines_static PUBLIC xtensor xtensor::optimize xtensor::use_xsimd)
