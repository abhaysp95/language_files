add_library(
	day3_lib SHARED
	inc/day3_util.hpp
	src/day3_util.cpp
	)

add_executable(day3 src/main.cpp)

install(TARGETS day3_lib DESTINATION lib
	TARGETS day3 DESTINATION bin)
