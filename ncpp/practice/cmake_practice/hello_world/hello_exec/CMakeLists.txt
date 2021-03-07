message(STATUS "==> CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "==> LIBRARY_OUTPUT_PATH: ${LIBRARY_OUTPUT_PATH}")
message(STATUS "==> CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "==> CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(cmake_good main.cpp)

# now we have to tell the linker to add say_hello library to cmake_good executable

# target-executable   type   library-name
target_link_libraries(cmake_good PRIVATE say_hello)
# this will also inherit include-directory of the say_hello library
