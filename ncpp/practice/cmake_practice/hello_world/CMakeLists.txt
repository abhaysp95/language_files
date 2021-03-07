cmake_minimum_required(VERSION 3.15)
project(HelloWorld VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

#message(STATUS "==> system : ${CMAKE_SYSTEM}")
#message(STATUS "==> system name : ${CMAKE_SYSTEM_NAME}")
#message(STATUS "==> system version : ${CMAKE_SYSTEM_VERSION}")
#message(STATUS "==> system processor : ${CMAKE_SYSTEM_PROCESSOR}")
#message(STATUS "==> host system name: ${CMAKE_HOST_SYSTEM_NAME}")

if (UNIX AND NOT APPLE)
	set(LINUX TRUE)
endif()

if(LINUX)
	message(STATUS "==> this is a linux system")
elseif(UNIX)
	message(STATUS "==> this is a unix system")
else()
	message(STATUS "==> this is a windows system")
endif()

# we need to have library target defined before the executable, cause executable requires library
# so with add_subdirectory(say-hello) being above this should not be the problem

# add_executable(cmake-good main.cpp helloworld.cpp)   you can just as well give the
# source file name you want to include
# but let's add it as a library


# moved this add_library call to say-hello library folder
# add_library(  # we didn't mention library type, cmake build it as a static library
	# you may give or give not the library type beside the library name
	#say_hello
	#say_hello SHARED
	#say_hello STATIC # there's a third type name MODULE
	#helloworld.hpp
	#helloworld.cpp
	#)


# bottom lines are moved to CMakeLists of hello_exec
# add_executable(cmake_good main.cpp)

# now we have to tell the linker to add say_hello library to cmake_good executable

#target_link_libraries(cmake_good PRIVATE say_hello)
