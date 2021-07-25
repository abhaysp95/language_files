cmake_minimum_required(VERSION 3.15)

project(Calculator LANGUAGES CXX)

add_library(calclib STATIC src/calclib.cpp include/calc/lib.hpp)
# public here(for library) means that any target(in this case 'calc') which
# links to this target(in this case 'calclib') must also need that include directory
# other options: PRIVATE(only affect current target, not dependencies) and
# INTERFACE(only needed for dependencies)
target_include_directories(calclib PUBLIC include)
target_compile_features(calclib PUBLIC cxx_std_14)

add_executable(calc apps/calc.cpp)
target_link_libraries(calc PUBLIC calclib)
