cmake_minimum_required(VERSION 3.15)

project(bgcpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
	"./program_files_and_preprocessing_directives/average.h"
	"./program_files_and_preprocessing_directives/functions.h"
	"./program_files_and_preprocessing_directives/ex10_10.cpp"
	"./program_files_and_preprocessing_directives/functions.cpp"
	"./program_files_and_preprocessing_directives/preprocessor_directives.cpp")

add_executable(bgcpp ${SOURCES})
add_subdirectory(./defining_your_own_data_types)
add_subdirectory(./operator_overloading)
add_subdirectory(./inheritance)
add_subdirectory(./polymorphism)
add_subdirectory(./runtime_errors_and_exceptions)
