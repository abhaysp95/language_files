add_executable(cmake_good main.cpp)

# now we have to tell the linker to add say_hello library to cmake_good executable

# target-executable   type   library-name
target_link_libraries(cmake_good PRIVATE say_hello)
# this will also inherit include-directory of the say_hello library
