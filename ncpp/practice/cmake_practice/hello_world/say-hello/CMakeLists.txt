add_library(
	say_hello SHARED
	src/say-hello/helloworld.hpp
	src/say-hello/helloworld.cpp
	)

# we need to define an include path for this library
# name-of-the-target   interface-mode   list-of-directories
target_include_directories(say_hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# PUBLIC means anyone consuming this library needs to also have to added same list-of-directories in their include-directories

# CMAKE_CURRENT_SOURCE_DIR will point to outer say-hello(one which contains the src folder)

# let's add a pre-processor definition to the library
target_compile_definitions(say_hello PUBLIC SAY_HELLO_VERSION="0.0.1")
# if I change it to PRIVATE it'll only be accessible to say_hello library
# if change to INTERFACE it'll be opposite of private
